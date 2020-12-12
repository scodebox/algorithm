#include<stdio.h>

int main(){
	int g[50][50],n,i,j,k;

	printf("Enter the number of vertices : ");
	scanf("%d",&n);

	printf("Enter the table : ");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);

	printf("The Table : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("  %d",g[i][j]);
		printf("\n");
	}

	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(i != k){
				for(j=0;j<n;j++){
					if(j != k){
						if(g[i][j] > g[i][k]+g[k][j]){
							g[i][j] = g[i][k]+g[k][j];
						}
					}
				}
			}
		}
	}

	printf("Result : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("  %d",g[i][j]);
		printf("\n");
	}
    return 0;
}