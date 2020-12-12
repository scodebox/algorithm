#include <stdio.h>

void merge(int* ar, int start, int mid, int end){
	int i, j;
	i = start;
	j = mid+1;
	int temp_index=start,b[100];

	while(i <= mid && j <= end){
		if (ar[i] <= ar[j]){
			b[temp_index++] = ar[i++];
		}
		if (ar[i] > ar[j]){
			b[temp_index++] = ar[j++];
		}
	}

	if(i>mid)
		while(j<=end)
			b[temp_index++] = ar[j++];
	if(j>end)
		while(i<=mid)
			b[temp_index++] = ar[i++];


	for(i=start;i<=end;i++)
		ar[i]=b[i];
}


void merge_sort(int* ar, int start, int end){
	if(start>=end) return;

	int mid = (start+end)/2;

	merge_sort(ar,start, mid);
	merge_sort(ar,mid+1,end);

	merge(ar,start, mid, end);
}


int main(int argc, char const *argv[]){
	int ar[100], len;
	int i,j;

	printf("\nENTER THE SIZE : ");
	scanf("%d",&len);

	printf("\nENTER %d ELEMENTS : ",len);
	for(i=0;i<len;i++)
		scanf("%d",&ar[i]);

	// Merge sort.
	merge_sort(ar,0,len-1);

	printf("\nSORTED : ");
	for(i=0;i<len;i++)
		printf("%d ",ar[i]);


	printf("\n");
	return 0;
}
