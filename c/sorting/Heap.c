#include <stdio.h>

void display(int* ar, unsigned int len){
	printf("\nDISPLAY : ");
	for(int i=1;i<=len;i++)
		printf("%d ",ar[i]);
}

void adjust(int* ar, int start, unsigned int size){
	int index = start*2;
	int item = ar[start];
	while(index <= size){
		if(index < size && ar[index+1] > ar[index])
			index++;
		if(item > ar[index])
			break;

		ar[index/2] = ar[index];
		index*=2;
	}
	ar[index/2] = item;
}


int delete_max_heap(int* ar,unsigned int size){
	int deleted_item = ar[1];
	printf("\nDELETED ELEMENT ::%d ",deleted_item);

	ar[1] = ar[size];
	adjust(ar,1,--size);

	return deleted_item;
}


void insert_into_max_heap(int* ar, int value, unsigned int position){
	while(position>1 && ar[position/2] < value){
		ar[position]=ar[position/2];
		position/=2;
	}
	ar[position] = value;
}

int main(int argc, char const *argv[]){
	int ar[100],value;
	unsigned int len=0;
	
	// Heap implementation.

	/*
	insert_into_max_heap(ar,10,++len);
	insert_into_max_heap(ar,15,++len);
	insert_into_max_heap(ar,20,++len);
	insert_into_max_heap(ar,30,++len);
	insert_into_max_heap(ar,16,++len);
	insert_into_max_heap(ar,35,++len);


	delete_max_heap(ar,len--);
	delete_max_heap(ar,len--);
	delete_max_heap(ar,len--);
	delete_max_heap(ar,len--);
	delete_max_heap(ar,len--);
	delete_max_heap(ar,len--);

	display(ar,len);

	*/




	// Buttom up approach 
	int heap[] = {0,2,5,7,3,2,4,7,9};
	unsigned int n = 8;

	for(int i=(n/2);i>=1;i--)
		adjust(heap,i,n);
	display(heap,n);

	
	printf("\n");
	return 0;
}