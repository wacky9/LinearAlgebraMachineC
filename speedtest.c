#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define THREAD_NO 100

void *array_mult(void* arr_struct);
void p_mat(double mat[THREAD_NO][THREAD_NO]);
double optionOne(double mat[THREAD_NO][THREAD_NO],double value);
double optionTwo(double mat[THREAD_NO][THREAD_NO],double value);

typedef struct {
	double* arr;
	double val;
} arr_num_pair;

int main(){
    double numA[THREAD_NO][THREAD_NO];
	double numB[THREAD_NO][THREAD_NO];

	double value = 10;
    //initialize array
	for(int i=0; i< THREAD_NO; i++){
		for(int j=0; j<THREAD_NO; j++){
            numA[i][j] = 5;
			numB[i][j] = 5;
		}
    }
	/*clock_t tic = clock();
	optionOne(numA,value);
	clock_t toc = clock();
	printf("Time: %f\n",(double)(toc-tic));
*/
	clock_t tic = clock();
	optionTwo(numA,value);
	clock_t toc = clock();
	printf("Time: %f\n",(double)(toc-tic));
	
    return 0;

}

double optionOne(double mat[THREAD_NO][THREAD_NO],double value){
	printf("TEST\n");
	pthread_t p[THREAD_NO];
	for(int a = 0; a<THREAD_NO; a++){
		arr_num_pair* newPair = calloc(1,sizeof(arr_num_pair));
		newPair->arr = mat[a];
		newPair->val = value; 
		pthread_create(&p[a], NULL, array_mult, (void*)newPair);
	}
	for(int a = 0; a<THREAD_NO; a++){
		pthread_join(p[a], NULL);
	}
	return 0.0;
}

double optionTwo(double mat[THREAD_NO][THREAD_NO],double value){
	printf("test\n");
	for(int i = 0; i<THREAD_NO; i++){
        for (int k = 0; k<THREAD_NO; k++){
            mat[i][k] = mat[i][k]*(value);
        }
    }
	return 0.0;
}

void p_mat(double mat[THREAD_NO][THREAD_NO]){
    for(int i = 0; i<THREAD_NO; i++){
        for(int k = 0; k<THREAD_NO; k++){
            printf("%f ",mat[i][k]);
        }
        printf("\r\n");
    }
}

/*Instead of using locks, it reduces the array by storing the sum of the 
 * array in the zero index of the array. No need for locks b/c each 
 * sub-array of num is kept separate, so they can be safely manipulated individually*/
void *array_mult(void *pair){
	arr_num_pair* p = (arr_num_pair*)pair;
	for(int i = 0; i<THREAD_NO; i++){
		p->arr[i] = p->arr[i]*p->val;
	}
}