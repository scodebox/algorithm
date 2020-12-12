#include<stdio.h>

void main(){
	int data[10] = {0,1,2,3,4,5,6,7,8,9};
	int l=0,se, flag = 0, mid,i,j,temp,h;
	
	printf("Enter the number of elements in list : ");
	scanf("%d",&h);
	
	printf("Enter the list elements : ");
	for(i=0;i<h;i++)
		scanf("%d",&data[i]);
		
	for(i=0;i<h;i++)
		for(j=0;j<h;j++)
			if(data[i] < data[j]){
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		
	printf("After sorting : ");	
	for(i=0;i<h;i++)
		printf("%d ",data[i] );
	printf("\n");
	
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
