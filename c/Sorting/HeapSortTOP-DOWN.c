#include <stdio.h>

void display(int* heap, int length){
	printf("\nDISPLAY :: ");
	
	for(int i=1; i<=length; i++)
		printf("%d ",heap[i]);
}

void adjust(int* heap, int start, int length){
	int index = start*2;
	int item = heap[start];

	while (index<=length){
		if(index<length && heap[index+1] > heap[index])
			index++;
		if(heap[index] < item)
			break;
		heap[index/2] = heap[index];
		index*=2;
	}

	heap[index/2] = item;
}

int delete_max_heap(int* heap,int size){
	int item = heap[1];
	heap[1] = heap[size];

	adjust(heap,1,--size);

	return item;
}

void build_heap(int* heap, int item, int position){
	while(position>1 && heap[position/2] < item){
		heap[position] = heap[position/2];
		position/=2;
	}
	heap[position] = item;
}

int main(int argc, char const *argv[]){
	int heap[100],item;
	unsigned int size;

	printf("\nENTER THE SIZE : ");
	scanf("%d",&size);

	for(int i=1;i<=size;i++){
		printf("\nENTER %d th ITEM : ",i);
		scanf("%d",&item);

		build_heap(heap,item,i);
	}



	for(int i=1;i<=size;i++){
		item = delete_max_heap(heap,size-(i-1));
		heap[size-(i-1)] = item;
	}

	display(heap,size);


	printf("\n");
	return 0;
}