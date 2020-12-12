#include<stdio.h>

void main(){
	int data[10] = {0,1,2,3,4,5,6,7,8,9};
	int i,se, flag = 0;

	printf("Enter the number for search : ");
	scanf("%d",&se);

	for(i=0;i<10;i++){
		if(data[i] == se){
			printf("Value found in %d th position.\n\n",i);
			flag = 1;
		}
	}

	if(flag == 0)
		printf("The value is not found in this list !\n");
}
