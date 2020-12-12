#include<stdio.h>

int a[100],i,j,n;

main()
{
	printf("\n------------------------------------\n");
	printf("\nENTER THE SIZE : ");
	scanf("%d",&n);
	printf("\nENTER %d NUMBERS : ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	mergesort(a,0,n-1);
	printf("\nMERGE SORT : ");
	for(i=0;i<n;i++)
		printf("%3d",a[i]);
		
	printf("\n\n");
}

mergesort(int a[], int i, int j)
{
	int mid;
	if(i>=j)	return;
	mid=(i+j)/2;
	mergesort(a,i,mid);
	mergesort(a,mid+1,j);
	merge(a,i,j);
}

merge(int a[], int i, int j)
{
	int b[10],k,mid,l,start;
	start=i;
	mid=(i+j)/2;
	k=mid+1;
	l=i;
	while(i<=mid && k<=j){
		if(a[i]<=a[k])
			b[l++]=a[i++];
			else
				b[l++]=a[k++];
	}
	if(i>mid)
		for(;k<=j;)	b[l++]=a[k++];
		else if(k>j)
				for(;i<=mid;)	b[l++]=a[i++];
	
	for(l=start; l<=j ;l++)
		a[l]=b[l];
}
