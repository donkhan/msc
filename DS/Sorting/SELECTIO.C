#include<stdio.h>
#include<conio.h>

main(){
	int a[] = {3,1,5,2,89,43,56};
	int i,j,k;
	int n = 7,t;
	clrscr();
	printf("Before Sorting....");
	for(k=0;k<n;k++){
			printf(" %d ",a[k]);
	}
	printf("\n");
	printf("Passes.....\n");
	for(i=0;i<n-1;i++){
		int minpos = i;
		for(j=i+1;j<n;j++){
			if(a[minpos] > a[j]){
				//min = a[j];
				minpos = j;
			}
		}
		t = a[i];
		a[i] = a[minpos];
		a[minpos] = t;
		for(k=0;k<n;k++){
			printf(" %d ",a[k]);
		}
		printf("\n");
		getch();
	}
	printf("\nAfter Sorting.....");
	for(i=0;i<n;i++){
		printf(" %d ",a[i]);
	}
	getch();
}