#include <conio.h>

int* partition(int *array,int start,int end,int no_of_elements);
int* merge(int* left_array,int* right_array, int left_array_length,int right_array_length,int size);

void print(int* array,int start,int end, int print_endl){
	int index;
	if(print_endl == 1)
		printf("No of Elements %d\n",end);
	for(index = start;index<end;index++)
		printf(" %d ",array[index]);
	if(print_endl == 1)
		printf("\n");
}

void print_pass(int* left_array,int* right_array,int left_array_length,int right_array_length){
	printf("Merging...");
	print(left_array,0,left_array_length,0);
	printf("   |   ");
	print(right_array,0,right_array_length,0);
	getch();
}


void test1(){
	int array[] = {3,1,5,6,8,9,2,4};
	int length = 8;
	int *sorted_array;
	printf("Test 1 - 8 elements Binary Split");
	printf("\nUnSorted Array....");
	print(array,0,length,1);
	sorted_array = partition(array,0,length-1,length);
	printf("Sorted Array....");
	print(sorted_array,0,length,1);
	getch();
}

void test2(){
	int array[] = {3,1,54,6,81,9,2,4,13};
	int length = 9;
	int *sorted_array;
	printf("Test 2 - 9 Elements Odd Numbers");
	printf("\nUnSorted Array....");
	print(array,0,length,1);
	sorted_array = partition(array,0,length-1,length);
	printf("Sorted Array....");
	print(sorted_array,0,length,1);
	getch();
}

void test3(){
	int array[] = {3,1,54,6,81,9,2,4,13,78,12,34};
	int length = 12;
	int *sorted_array;
	printf("Test 2 - 12 Elements Even Numbers but not binary");
	printf("\nUnSorted Array....");
	print(array,0,length,1);
	sorted_array = partition(array,0,length-1,length);
	printf("Sorted Array....");
	print(sorted_array,0,length,1);
	getch();
}

int main(){
	clrscr();
	test1();
	clrscr();
	test2();
	clrscr();
	test3();
	return 0;
}




int* merge(int* left_array,int* right_array,int left_array_length,int right_array_length,int size){
	int* result_array = malloc(sizeof(int)*size);
	int result_array_index = 0,first_array_index = 0,second_array_index = 0;
	print_pass(left_array,right_array,left_array_length,right_array_length);
	while(first_array_index < left_array_length && second_array_index < right_array_length)
		if(left_array[first_array_index] < right_array[second_array_index])
			result_array[result_array_index++] = left_array[first_array_index++];
		else
			result_array[result_array_index++] = right_array[second_array_index++];
	while(first_array_index < left_array_length)
		result_array[result_array_index++] = left_array[first_array_index++];
	while(second_array_index < right_array_length)
		result_array[result_array_index++] = right_array[second_array_index++];
	printf("\n After Merge...");
	print(result_array,0,left_array_length+right_array_length,1);
	return result_array;
 }

int* partition(int *array,int start,int end,int no_of_elements){
	int mid = (start + end + 1) / 2;
	int left_array_length = no_of_elements/2;
	int right_array_length = no_of_elements/2;
	if(no_of_elements % 2 == 1)
		right_array_length = right_array_length + 1;
	if(end-start > 0)
		return merge(partition(array,start,mid-1,left_array_length),
			partition(array,mid,end,right_array_length),
			left_array_length,right_array_length,left_array_length + right_array_length);
	return &array[mid];
}

