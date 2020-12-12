#include <stdio.h>

void main(){
	int i,j,k,n;
	float vw[10],weight[10],value[10],capacity,mp=0;

	printf("Enter the items : ");
	scanf("%d",&n);

	printf("Enter the capacity of Knapsack : ");
	scanf("%f",&capacity);

	printf("Enter the value & weight of items : ");
	for(i=0;i<n;i++)
		scanf("%f%f",&value[i],&weight[i]);

	printf("\nValue :  ");
	for(i=0;i<n;i++)
		printf("  %3.1f",value[i]);
	printf("\nWeight : ");
	for(i=0;i<n;i++)
		printf("  %3.1f",weight[i]);


	for(i=0;i<n;i++)
		vw[i] = value[i]/weight[i];

	// printf("\n");
	// for(i=0;i<n;i++)
	// 	printf(" %f",vw[i]);

	float temp;
	for(i=0;i<n;i++)
		for(j=i+1; j<n;j++){
			if(vw[i] < vw[j]){
				temp = vw[i];
				vw[i] = vw[j];
				vw[j] = temp;

				temp = value[i];
				value[i] = value[j];
				value[j] = temp;

				temp = weight[i];
				weight[i] = weight[j];
				weight[j] = temp;				
			}
		}

	i=0;
	while(capacity >= weight[i]){
		capacity-=weight[i];
		mp+=value[i];
		i++;
	}
	mp+=vw[i]*capacity;

	printf("\n\nMaximum profit : %.1f\n",mp);
}