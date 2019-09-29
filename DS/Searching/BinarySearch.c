#include<stdio.h>

void printArray(int length,int a[]){
	for(int i  = 0;i<length;i++){
		printf("  %d  ",a[i]);
	}
}

int bs(int a[],int length,int key){
	int low = 0;
	int high = length;
	printf("\n------------------------------------------\n");
	printArray(length,a);
	int pass = 1;
	printf("\nFind Element %d\n",key);
	while(low < high-1){
		int mid = (low + high)/2;
		printf("Low %d High %d Mid %d comparing Element %d Pass %d \n",low,high,mid,a[mid],pass);
		if(a[mid] == key){
			return mid;
		}
		if(a[mid] > key){
			high = mid;
		}else{
			low = mid;
		}
		pass++;
	}	
	return -1;
}

int main(){
	int a[] = {12,23,45,56,89,123,234,456};
	int key;
	int len = 8;
	char c;

	printf("23 is found at %d\n",bs(a,len,23));
	printf("12 is found at %d\n",bs(a,len,12));
	printf("234 is found at %d\n",bs(a,len,234));
	printf("456 is found at %d\n",bs(a,len,456));
	printf("567 is found at %d\n",bs(a,len,567));
	printf("6 is found at %d\n",bs(a,len,6));
	printf("44 is found at %d\n",bs(a,len,44));
	
	while(1){
		printf("Press c to continue. other character to quit.....");
		scanf("%c",&c);
		if(c == 'c'){
			printf("Enter Key to search ");
			scanf("%d",&key);
			printf("%d is found at %d\n",key,bs(a,len,key));
		}else{
			break;
		}	
	}

}
