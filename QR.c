#include "lin_alg_mac.h"

/*A numerically stable grahm-Schmidt orthogonalization, using Projections*/
Mat* stable_GS(Mat* mat){
    
}

/*Returns two matrices, where the first is Q and the second is R, using Householder factorizations
Requires row>=col*/
Mat** householder(Mat* mat){
    int n = mat->col;
    Mat* R = zero_constructor(mat->row,mat->col);
    for(int k = 1; k<n; k++){
        /*x is a column vector of column k of mat*/
        Mat* v = sub_matrix(mat,mat->row,1,0,k);
        v = add(scal_mul(v,sign(v->matrix[0][0]) * euclid_norm(v,false)),v);
        v = scal_mul(v,1/(euclid_norm(v,false)));
        Mat* A = sub_matrix(mat,mat->row-k,mat->col-k,k-1,k-1);
        
    }
}