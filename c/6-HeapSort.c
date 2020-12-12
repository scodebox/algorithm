#include<stdio.h>

void heapify(int a[], int i, int n){
	int l, r, t, lrg;
	l = i * 2;
	r = (i * 2) + 1;
	
	if( l <= n && a[l] >=a[i])
		lrg = l;
	else
		lrg = i;
	
	if( r <= n && a[r] >= a[lrg])
		lrg = r;
	
	if(lrg != i){
		t = a[lrg];
		a[lrg] = a[i];
		a[i] = t;
		
		heapify(a,lrg,n);
	}
}

void buildheap(int a[], int n){
	int i;
	
	for(i = (n / 2); i >= 1; i--)
		heapify(a,i,n);
}

void heapsort(int a[], int n){
	int temp, i;
	
	buildheap(a,n);
	
	for(i=n; i>=2; i--){
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;
	
		heapify(a,1,i-1);
	}
}

void main(){
	int i, n, a[50];
	
	printf("ENTER THE SIZE : ");
	scanf("%d",&n);
	
	printf("ENTER %d ELEMENTS ",n);
	
	for(i=1; i<=n; i++)
		scanf("%d",&a[i]);
		
	printf("\nYOU ENTERED : ");
	
	for(i=1; i<=n; i++)
		printf(" %d",a[i]);
	
	heapsort(a,n);
		
	printf("\nHEAP SORT : ");
	
	for(i=1; i<=n; i++)
		printf(" %d",a[i]);
		
	printf("\n");
}
