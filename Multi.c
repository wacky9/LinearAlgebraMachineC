#include "lin_alg_mac.h"
#include <math.h>
/*Contains void functions to be used in multi-threaded algorithms*/

/*Multiplies all the elements in an array by a single value*/
void *vec_mult(void *pair){
	arr_num_pair* p = (arr_num_pair*)pair;
	for(int i = 0; i<p->size; i++){
		p->newArr[i] = p->arr[i]*p->val;
	}
}

void* vec_add(void *pair){
    vec_pair* p = (vec_pair*)pair;
    for(int i = 0; i<p->size; i++){
        p->VecSum[i] = p->VecA[i]+ p->VecB[i];
    }
}

/*Unlike vec_add, VecSum is an actual double pointer here, not an array*/
void* vec_compress(void* pair){
    vec_pair* p = (vec_pair*)pair;
    double val = 0.0;
    for(int i = 0; i<p->size; i++){
        val += (p->VecA[i]) * (p->VecB[i]);
    }
    /*Sets the value of the memory address pointed to by VecSum 
    equal to val*/
    *(p->VecSum) = val;
}

void* line_transpose(void* line){
    vec_line* Line = (vec_line*)line;
    for(int i = Line->r; i<Line->r + LINE; i++){
        Line->write->matrix[Line->c][i] = Line->read->matrix[i][Line->c];
    }
}

/*Finds and returns the maximum of a single row starting from column i*/
void* row_max(void* line){
    vec_max* vm = (vec_max*)line;
    double max = fabs(vm->row[vm->i]);
    for(int j = vm->i + 1; j<vm->N; j++){
        double val = fabs(vm->row[j]);
        if(max < val){
            max = val;
        }
    }
    /*max_val is a pointer to where the max values should be stored. De-reference it
    and store max there*/
    *(vm->max_val) = max;
}