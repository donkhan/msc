#include<stdio.h>
#include<stdlib.h>

void print(int *array,int start,int end,int print_endl);
int* partition(int *array,int start,int end);
int* merge(int *left_array,int *right_array,int left_array_length,int right_array_length);

int main(){
	int array[] = {3,1,2,6,8,7,9,4,5,23,11,12,0,8,3};
	int length = 15;
	print(array,0,length,1);
	print(partition(array,0,length),0,length,1);
	return 1;
}

void print(int *array,int start,int end,int print_endl){
	int index;
	for(index = start;index<end;index++)
		printf(" %d ",array[index]);
	if(print_endl == 1)
		printf("\n");
}

void print_pass(int *left_array,int *right_array,int left_array_length,int right_array_length){
	printf("Merging....");
	print(left_array,0,left_array_length,0);
	printf("  |  ");
	print(right_array,0,right_array_length,0);
}


int* merge(int *left_array,int *right_array,int left_array_length,int right_array_length){
	int* result_array = malloc(sizeof(int)*(left_array_length + right_array_length));
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
	printf("\nAfter Merge...");
	print(result_array,0,left_array_length+ right_array_length,1);
	return result_array;
}

int* partition(int* array,int start,int end){
	int mid = (start + end)/2;
	int left_array_index=0,right_array_index=0;
	int *left_array = malloc(sizeof(int) * mid);
	int *right_array = malloc(sizeof(int) * (end-mid));
	if (end-start > 1){
		for(left_array_index = 0;left_array_index<mid;left_array_index++)
			left_array[left_array_index] = array[left_array_index];
		for(right_array_index=0;right_array_index<end-mid;right_array_index++)
			right_array[right_array_index] = array[mid+right_array_index];
		return merge(partition(left_array,0,left_array_index),partition(right_array,0,right_array_index),left_array_index,right_array_index);
	}
	return array;
}
