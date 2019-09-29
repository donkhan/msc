#include<stdio.h>

int main(){
	int a[] = {2,4,6,8,10};
	int *b = a + 4;
	int i = 0,sum = 0;
	for(i = 0;i<5;i++){
		sum = sum + (*b -i) - *(b-i);
		printf("%d\n",sum); 
	}
	printf("%d",*b);
}
