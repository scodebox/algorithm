#include<stdio.h>

void main(){
	int data[10] = {0,1,2,3,4,5,6,7,8,9};
	int l=0,se, flag = 0, h = 10, mid;
	printf("Enter the number for search : ");
	scanf("%d",&se);
	
	while(l <= h){
		mid = (l+h)/2;
		if(data[mid] == se){
			printf("The value is found in %d position !\n\n",mid);
			flag = 1;
			return;
		}
		else
		if(data[mid] < se){
			l = mid+1;
		}else
		if(data[mid] > se){
			h = mid-1; 		
		}
	}

	if(flag == 0){
		printf("Value is not found is this list !\n");
	}
	
}
