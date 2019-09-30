#include<stdio.h>
#include<conio.h>

int main(){
	int a[] = {1,2,3,4,5,7,9,11,13,14,15,19,20};
	int key = 0;
	int i = 0;
	int low = 0,high = 0,mid = 0;
	int found = 0;
	clrscr();
	for(i = 0;i<12;i++){
		printf(" %d ",a[i]);
	}
	do{
		found = 0;
		low = 0; high = 12; mid = (low + high)/2;
		printf("\n Enter the Key to Search...");
		scanf("%d",&key);

		while (low < high-1){
			mid = (low + high) /2;
			//printf("Low %d High %d Mid %d\n",low,high,mid);
			printf("Comparing %d with %d\n",a[mid],key);
			if(a[mid] == key){
				printf("Key %d is present at pos %d \n",key,mid);
				found = 1;
				break;
			}
			if(a[mid] < key){
				low = mid;
			}
			if(a[mid] > key){
				high = mid;

			}
		}
		if(found == 0){
			printf("Key %d is not found\n",key);
		}
		printf("Press q to quit. Press any other key to continue...");
	}while(getch() != 'q');
	return 1;

}