#include<conio.h>
#include<stdio.h>

void print(int a[],int len){
	int i;
	for(i = 0;i<=len;i++){
		printf(" %d ",a[i]);
	}
	printf("\n");
}

void swap(int *a,int *b){
	int t= *a;
	*a  = *b;
	*b = t;
}


qs(int a[],int l,int r,int length){
	int pass = 0;
	int pos = l;
	int pivot = a[pos];
	int i = l+1,j = r;
	//printf("Pivot is %d\n",pivot);
	//printf("i = %d j = %d\n",i,j);
	while(i < j){
		while(a[i] < pivot && i <= length){
			i++;
		}
		while(a[j] > pivot && j >= 0){
			j--;
		}
		if(i < j){
			//printf("Swap %d %d \n",a[i],a[j]);
			swap(&a[i],&a[j]);
		}else{
			//printf("Fswap %d %d \n",a[pos],a[i-1]);
			swap(&a[pos],&a[i-1]);
			qs(a,l,i-1,length);
			qs(a,j+1,r,length);
		}
		print(a,length);
		//getch();
	}
}

void main(){
	int a[] = { 111,23,56,145,22,7,3,154,67 };
	int len = 8;
	clrscr();
	printf("UnSorted Array....\n");
	print(a,len);
	getch();
	qs(a,0,len,len);
	printf("Sorted Array...\n");
	print(a,len);
	getch();
}