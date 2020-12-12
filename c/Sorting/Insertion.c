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

	int item;
	// Insertion sort.
	for(i=0;i<len;i++){
		j=i;
		item = ar[i+1];
		while (j>=0 && ar[j] > item){
			ar[j+1] = ar[j];
			j--;
		}
		ar[j+1] = item;
	}


	printf("\nSORTED : ");
	for(i=0;i<len;i++)
		printf("%d ",ar[i]);


	printf("\n");
	return 0;
}