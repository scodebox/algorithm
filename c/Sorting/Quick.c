#include <stdio.h>

int partition(int* ar, int start, int end){
	int pivot = ar[start];
	int temp;

	int i = start;
	int j = end+1;

	do{
		do{
			i++;
		}while((ar[i] < pivot) && i < end);
		
		do{
			j--;
		}while((ar[j] > pivot) && j > start);

		if(i<j){
			temp = ar[i];
			ar[i] = ar[j];
			ar[j] = temp;
		}
	}while(i<j);

	temp = ar[start];
	ar[start] = ar[j];
	ar[j] = temp;

	return j;
}


void quick_sort(int* ar,int start, int end){
	if (start >= end)	return;
	int pivot = partition(ar,start,end);
	quick_sort(ar,start,pivot-1);
	quick_sort(ar,pivot+1,end);
}


int main(int argc, char const *argv[]){
	int ar[100], len;
	int i,j;

	printf("\nENTER THE SIZE : ");
	scanf("%d",&len);

	printf("\nENTER %d ELEMENTS : ",len);
	for(i=0;i<len;i++)
		scanf("%d",&ar[i]);

	// Quick sort.
	quick_sort(ar,0,len-1);

	printf("\nSORTED : ");
	for(i=0;i<len;i++)
		printf("%d ",ar[i]);


	printf("\n");
	return 0;
}