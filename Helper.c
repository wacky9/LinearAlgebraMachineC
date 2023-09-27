#include "lin_alg_mac.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
double sign(double num){
    if(num<0){
        return -1.0;
    } else {
        return 1.0;
    }
}

bool same_mat(Mat* A, Mat* B){
    if(A->row == B->row && A->col == B->col){
        for(int i = 0; i<A->row; i++){
            for(int j = 0; j<A->col; j++){
                if(!equal_double(A->matrix[i][j], B-> matrix[i][j])){
                    #if TEST
                    printf("\n%d %d",i,j);
                    #endif
                    return false;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}
/*From realtimecollisiondetection.net*/
bool equal_double(double x, double y){
    return abs(x-y) <= fmax(ABSOLUTE_EPSILON,RELATIVE_EPSILON*fmax(abs(x),(abs(y))));
}