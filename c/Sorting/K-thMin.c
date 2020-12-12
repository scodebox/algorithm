#include <stdio.h>

void display(int* ar, int size){
	printf("\nDISPLAY :: ");
	for(int i=0;i<size;i++)
		printf("%d ",ar[i]);
}

int partition(int* ar, int start, int end){
	int i=start;
	int j=end+1;
	int pivot = ar[start];
	int temp;

	do{
		do{
			i++;
		}while(ar[i] < pivot && i< end);
		do{
			j--;
		}while(ar[j]>pivot && j > start);
		if(i<j){
			temp = ar[i];
			ar[i] = ar[j];
			ar[j] = temp;
		}
	}while(i<j);

	temp = ar[j];
	ar[j] = ar[start];
	ar[start] = temp;
	return j;
}


int find_kth_min(int* ar,int start, int end, int k){
	int pivot = partition(ar,start,end);
	if(pivot == k)
		return k;
	if(pivot>k){
		return find_kth_min(ar,start,pivot-1,k);
	}
	if(pivot<k){
		return find_kth_min(ar,pivot+1,end,k);
	}
}



int main(int argc, char const *argv[])
{
	int ar[100],size,k,kth_min;

	printf("\nENTER THE SIZE : ");
	scanf("%d",&size);

	printf("\nENTER %d ELEMENTS : ",size);
	for(int i=0;i<size;i++)
		scanf("%d",&ar[i]);


	printf("\nENTER K VALUE : ");
	scanf("%d",&k);

	if(k<size)
		kth_min = find_kth_min(ar,0,size,k);
	else
		printf("\nOUT OF BOUND!");

	printf("\nK th MIN : %d\n",kth_min);

	return 0;
}