#include <stdio.h>

int main(int argc, char const *argv[])
{
	int ar[100], len;
	int i,j;

	printf("\nENTER THE SIZE : ");
	scanf("%d",&len);

	printf("\nENTER %d ELEMENTS : ",len);
	for(i=0;i<len;i++)
		scanf("%d",&ar[i]);

	int temp;

	// Bubble sort.
	for(i=0;i<len-1;i++)
		for(j=0;j<len-i;j++){
			if(ar[j] > ar[j+1]){
				temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
		}


	printf("\nSORTED : ");
	for(i=0;i<len;i++)
		printf("%d ",ar[i]);


	printf("\n");
	return 0;
}