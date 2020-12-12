#include<stdio.h>
int input;

int search(int data[], int l, int h){
	int mid = (l+h)/2;
	if(l > h)
		return 0;
	else{
			if(data[mid] == input)
				return mid;
		else{
			if(data[mid] > input)
				search(data,l,(mid-1));
			else 
				if(data[mid] < input)
					search(data,(mid+1),h);
			}
	}
}

void main(){

	int data[10] = {0,1,2,3,4,5,6,7,8,9};
	int l = 0,h = 10, flag =0;
	
	printf("Enter data for search : ");
	scanf("%d",&input);

	flag = search(data,l,h);

	if(flag != 0)
		printf("Value found in %d position\n",flag);
	else
		printf("Value not found !\n");
}
