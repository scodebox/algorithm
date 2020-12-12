#include<stdlib.h>
#include<stdio.h>
 
#define MAX_INT 10000000
 
int matrixMultiplication(int p[], int N){
 
  int L,i, j, temp;
 
  int M[N][N];
 
  for(i=0; i<N; i++){
  	for(j=0; j<N; j++){
       M[i][j] = 0;
  	}
  }       
 
  for(L=2; L<N; L++){
    /* For every position i, we check every chain of len L */
    for(i=1; i<N-L+1; i++){
 
        j = i+L-1;
        M[i][j] = MAX_INT;
        /* For matrix i to j, check every split K */
            for(int k=i; k<j; k++){
                temp = M[i][k] + M[k+1][j] + p[i-1] * p[k] * p[j];
               /* Check if the current count is less than minimum */
                if(temp < M[i][j]){
                    M[i][j] = temp;                 
                }
            }
        }
    }
    for(i=1; i<N; i++){
    	for(int k=1; k<N; k++){
    		printf("%d ", M[i][k]);
    	}
    	printf("\n");
    }
 
 return M[1][N-1];
}
/* Driver program to run above code */
int main(){
 
    int p [] ={10, 20, 30, 40, 30};
    int n = sizeof(p)/sizeof(p[0]);
 
    printf("\nLeast Multiplication : %d\n", matrixMultiplication(p,n));
 
    return 0;
}
 
