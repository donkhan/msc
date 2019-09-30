#include<stdio.h>
#include<conio.h>

int main(){
	int a[] = {3,1,5,2,89,43,56};
	int i,j,k,t,key,pass, n = 7;

	clrscr();
	printf("Before Sorting....");
	for(k=0;k<n;k++){
		printf(" %d ",a[k]);
	}
	printf("\n");
	printf("Passes.....\n");
	for(i=1;i<n;i++){
		j = i - 1;
		key = a[i];
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j = j -1;
		}
		a[j+1] = key;
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
	return 0;
}