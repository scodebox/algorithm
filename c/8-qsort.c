#include <stdio.h>

int A[10],n,i,j;

main()
{
	printf("\nENTER THE SIZE : ");
	scanf("%d",&n);

	printf("\nENTER %d NUMBERS : ",n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);

	qsort(A,0,n-1);

	printf("\nQ SORT : ");
	for(i=0;i<n;i++)
		printf("%3d",A[i]);

	printf("\n\n");
}

qsort(int A[], int i, int j)
{
	int k;
	if(i>=j)	return;

	partition(A,i,j,&k);
	qsort(A,i,k-1);
	qsort(A,k+1,j);
}

partition(int A[],int i,int j, int *l)
{
	int B[10],m,n,p,q,count=0;

	p=A[i];
	m=i+1;
	n=j;
	//count=0;

	for(q=i+1;q<=j;q++)
		if(A[q]<=p){
			B[m++]=A[q];
			count++;
		}
		else
			B[n--]=A[q];

	B[i]=B[i+count];
	B[i+count]=p;

	*l=i+count;

	for(q=i;q<=j;q++)
		A[q]=B[q];

}