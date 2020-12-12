#include <stdio.h>

void display(int* heap, unsigned int size){
	printf("\nDISPLAY :: ");
	
	for(int i=1;i<=size;i++)
		printf("%d ",heap[i]);
}

void adjust(int* heap, int start,unsigned int size){
	int item = heap[start];
	int index = start*2;

	while(index <= size){
		if(index<size && heap[index+1] > heap[index])
			index++;
		if(heap[index] < item)
			break;
		heap[index/2] = heap[index];
		index*=2;
	}

	heap[index/2] = item;
}

int delete_max_heap(int* heap, unsigned int size){
	int item = heap[1];
	heap[1] = heap[size];

	adjust(heap,1,size-1);

	return item;

}


int main(int argc, char const *argv[])
{
	int heap[100],item;
	unsigned int size;
	printf("\nENTER THE SIZE : ");
	scanf("%d",&size);

	printf("\nENTER %d ELEMENTS : ",size);
	for(int i=1;i<=size;i++)
		scanf("%d",&heap[i]);

	for(int i=size/2; i>=1; i--)
		adjust(heap, i, size);

	
	for(int i=1;i<=size;i++){
		heap[size-(i-1)] = delete_max_heap(heap,size-(i-1));
	}

	display(heap,size);

	printf("\n");
	return 0;
}