#include<stdio.h>
#include<conio.h>

int main(){
	int a[] = {34,56,78,12,3,322};
	int i,found,key;
	int n = 6;
	clrscr();
	for(i = 0;i<n;i++){
		printf("   %d  ",a[i]);
	}
	do{
		found = -1;
		printf("\n Input the Key to Search...");
		scanf("%d",&key);
		i = 0;
		while(i < n){
			if(a[i] == key){
				printf("Key %d is found at pos %d\n",key,i);
				found = 0;
				break;
			}
			i++;
		}
		if(found == -1){
			printf(" Key %d is not found",key);
		}
		printf("\nPress q to quit. Press any key to search again\n");
	}while(getch() != 'q');
	return 1;
}