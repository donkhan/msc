#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"
#include "validity.h"
#include "convert.h"


void append(char *src,char* dst,int pos,int length){
	int i;
	for(i = 0;i<length;i++){
		dst[i+pos] = src[i];
	}
}

char* pluck(char *src,int pos, int length){
	char *dst = (char *)malloc(length);
	int i = 0;
	for(i = 0;i<length;i++){
		dst[i] = src[i+pos];
	}
	return dst;
}

void print_bytes(char *s){
	int bytes = 0;
	int length = strlen(s);
	printf("\nBinary: %s (%d) bits ",s,length);
	printf("\nByte Split: ");
	for(int i = 0;i<length;i++){
		if(i%8 == 0 && i != 0){
			printf(",");
			bytes = bytes + 1;
		}
		printf("%c",s[i]);
	}
	printf(" (%d) Bytes",bytes+1);
	printf("\n");
}

void print_start(char* header){
	printf("\n************** %s ***************\n",header);
}

void print_end(char* header){
	printf("\n************** End of %s ***************\n",header);
}

int get_int_input(char* field){
	int input;
	printf("Enter %s : ",field);
	scanf("%d",&input);
	return input;
}

char get_option(){
	int option;
	printf("(e/c) ? ...");
	option = fgetc(stdin);
	while(option != 'e' && option != 'c'){
		option = fgetc(stdin);
	}
	return option;
}

void gulp_go_ahead(){
	printf("\nPress enter to continue...");
	char option = fgetc(stdin);
	while(option != 10){
		option = fgetc(stdin);
	}
}

int get_int_input_new(char* field,int old_value){
	printf("%s = (%d)   ",field,old_value);
	char option = get_option();
	if(option == 'c'){
		int input = old_value;
		printf("Enter %s : ",field);
		scanf("%d",&input);
		return input;
	}
	return old_value;
}

int get_int_input_between(char* field,int old_value,int min,int max){
	printf("%s = (%d)   ",field,old_value);
	char option = get_option();
	if(option == 'c'){
		int input = old_value;
		do{
			printf("Enter %s between (%d - %d): ",field,min,max);
			scanf("%d",&input);
		}while(input <= min || input >= max);
		return input;
	}
	return old_value;
}

char* get_string_input_new(char * field, char *old_value){
	char* input = old_value;
	printf("%s = (%s) ",field,input);
	char option = get_option();
	if(option == 'c'){
		printf("Enter %s : ",field);
		scanf("%s",input);
		return input;
	}
	return input;
}

char* get_application_payload(){
	char *app_payload = calloc(32,sizeof(char));
	printf("Enter Application Payload...");
	scanf("%s",app_payload);
	return app_payload;
}


char* get_string_input_with_valid_check(char * field, char *old_value,char *type){
	char* input = old_value;
	printf("%s = (%s) ",field,input);
	char option = get_option();
	if(option == 'c'){
		do{
			printf("Enter %s : ",field);
			scanf("%s",input);
		}while(is_valid(input,type) == 0);
		return input;
	}
	return input;
}

int is_valid(const char* input,char *type){
	if(strcmp(type,"mac") == 0){
		return is_valid_mac(input);
	}
	if(strcmp(type,"ip") == 0){
		return is_valid_ip(input);
	}
	return 1;
}





