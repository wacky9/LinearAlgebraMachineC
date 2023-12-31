#include "lin_alg_mac.h"
#include <math.h>
#include <pthread.h>
/*mat is an augmented matrix. Returns a row-reduced matrix*/
Mat* elimination(Mat* mat){
   Mat* newMat = sub_matrix(mat,mat->row,mat->col,0,0);
   for(int i = 0; i<mat->row; i++){
        Mat* upperRow = sub_matrix(newMat,1,newMat->col,i,0);
        for(int k = i+1; k<newMat->row; k++){
            /*Fetch the row to be modified*/
            Mat* replace_row = sub_matrix(newMat,1,newMat->col,k,0);
            double a = upperRow->matrix[0][i];
            double b = replace_row->matrix[0][i];
            Mat* elimination_row = scal_mul(upperRow,-b/a);
            Mat* newRow = add(elimination_row,replace_row);
            unravel_mat(replace_row);
            unravel_mat(elimination_row);
            newMat->matrix[k] = newRow->matrix[0];
        }
   }
   return newMat;
}

/*mat is a row-reduced, augmented, non-singular matrix w/no extra rows of zeroes
Returns a solution column vector*/
Mat* backsubstitution(Mat* mat){
    Mat* results = zero_constructor(mat->col-1,1);
    short end_column = mat->col-1;
    short c = end_column -1;
    for(int r = mat->row-1; r>=0; r--){
        double x = mat->matrix[r][end_column];
        for(int i = c+1; i<end_column; i++){
            double val = mat->matrix[r][i] * results->matrix[i][0];
            x-=val;
        }
        x /= mat->matrix[r][c];
        results->matrix[c][0] = x;
        c--;
    }
    return results;
}

/*Requires an augmented matrix
  Returns the index of the row to be swapped with row i*/
short scaled_partial_pivoting(short i, Mat* mat){
    double* max_vector = row_maxes(i,mat);
    short pivot_row = i;
    double pivot = fabs(mat->matrix[i][i])/max_vector[0];
    for(j = i+1; j<mat->row; j++){
        double test_pivot= fabs(mat->matrix[j][i])/max_vector[j-i];
        if(pivot < test_pivot){
            pivot = test_pivot;
            pivot_row = j;
        }
    }
    return pivot_row;
}

/*Returns an array of the maximum values in each row starting at row i and only going from col i to end of the row*/
double* row_maxes(short i, Mat* mat){
    /*Start at i-th row*/
    short row_num = mat->row - i;
    double* maxes = (double*)calloc(row_num,sizeof(double));
    pthread_t p[row_num];
    for(int j = 0; j<row_num; j++){
        vec_max* vm = (vec_max*)calloc(1,sizeof(vec_max));
        /*i is the column to start at, N is the column to stop at*/
        vm->i = i;
        vm->N = mat->col;
        vm->max_val = &maxes[j];
        /*Need to add i to account for offset*/
        vm->row = mat->matrix[j+i];
		pthread_create(&p[j], NULL, vec_mult, (void*)newPair);
	}
	for(int a = 0; a<row_num; a++){
		pthread_join(p[a], NULL);
	}
    return maxes;
}