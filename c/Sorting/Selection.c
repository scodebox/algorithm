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

	int temp,minpos=0;


	// Selection sort.
	for(i=0;i<len;i++){
		minpos=i;
		for(j=i+1;j<len;j++)
			if(ar[minpos] > ar[j])
				minpos = j;

		temp = ar[minpos];
		ar[minpos] = ar[i];
		ar[i] = temp;
	}


	printf("\nSORTED : ");
	for(i=0;i<len;i++)
		printf("%d ",ar[i]);


	printf("\n");
	return 0;
}