#include<stdio.h>
#include<conio.h>

main(){
	int a[] = {3,1,5,2,89,43,56};
	int i,j,k;
	int n = 7;
	clrscr();
	printf("Before Sorting....");
	for(i=0;i<n;i++){
		printf(" %d ",a[i]);
	}
	printf("\n Passes \n");
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i] > a[j]){
				int t= a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		printf("\n");
		for(k=0;k<n;k++){
			printf(" %d ",a[k]);
		}
                getch();
	}
	printf("\nAfter Sorting.....");
	for(i=0;i<n;i++){
		printf(" %d ",a[i]);
	}
	printf("\n");

	getch();

}