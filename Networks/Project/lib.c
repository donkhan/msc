#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"

char* int_to_binary(int value,int length){
	int c;
	int k;
	char* v = (char *)malloc(length);
	int i = 0;
	for (c = length-1; c >= 0; c--){
	    k = value >> c;
	    if (k & 1){
	    	v[i++] = '1';
	    }
	    else{
	    	v[i++] = '0';
	    }
	}
	return v;
}

char* int_star_to_binary(unsigned int* ptr,int no_of_bytes){
	int c;
	int k;
	char* v = (char *)malloc(no_of_bytes * 32);
	int i = 0;
	int j = 0;
	int value = 0;

	for(i = 0;i<no_of_bytes;i++){
		value = ptr[i];
		j = i*32;
		for (c = 31; c >= 0; c--){
			k = value >> c;
			if (k & 1){
				v[j++] = '1';
			}
			else{
				v[j++] = '0';
	    	}
		}
	}
	return v;
}

int fromBinary(const char *s) {
  return (int) strtol(s, NULL, 2);
}

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
	printf("\nBinary: %s Length %d ",s,length);
	printf("\nOctet Split: \n");
	for(int i = 0;i<length;i++){
		if(i%8 == 0 && i != 0){
			printf(",");
			bytes = bytes + 1;
		}
		printf("%c",s[i]);
	}
	printf("\n");
}

char* get_4_octets(char* a){
	char* address = calloc(32,sizeof(char));
	char* token = strtok(a,".");
	while(token != NULL){
		address = strcat(address,int_to_binary(atoi(token),8));
		token = strtok(NULL,".");
	}
	return address;
}


char* toIP(char* a){
	char *token;
	char *address;
	char buf[8];
	char x[15];
	int k = 0;
	for(int i = 0;i<4;i++){
		token = pluck(a,i*8,8);
		char *format = "%d";
		int value = fromBinary(token);
		int len = 1;
		if(value > 99) len = 3;
		else if(value > 9) len = 2;
		snprintf(buf, len+1,format, value);
		for(int j = 0;j<strlen(buf);j++){
			x[k] = buf[j];
			k = k + 1;
		}
		x[k] = '.';
		k = k + 1;
	}
	k = k - 1;
	address = calloc(k,sizeof(char));
	for(int i = 0;i<k;i++){
		address[i] = x[i];
	}
	return address;
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
	printf(" e-continue c-change ");
	option = fgetc(stdin);
	while(option != 'e' && option != 'c'){
		option = fgetc(stdin);
	}
	return option;
}

void gulp_go_ahead(){
	printf("\n Press c to Continue...");
	char option = fgetc(stdin);
	while(option != 'c'){
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

char* get_6_octets(char* mac){
	char* address = calloc(96,sizeof(char));
	char* token = strtok(mac,":");
	while(token != NULL){
		char* binary = calloc(8 ,sizeof(char));
		int i = 0;
		char* first_nibble = calloc(4,sizeof(char));
		if(strlen(token) == 1){
			first_nibble = strcpy(first_nibble,"0000");
		}
		while (token[i]) {
			switch (token[i]) {
				case '0': binary = strcat(binary,"0000");break;
				case '1': binary = strcat(binary,"0001");break;
				case '2': binary = strcat(binary,"0010");break;
				case '3': binary = strcat(binary,"0011");break;
				case '4': binary = strcat(binary,"0100");break;
				case '5': binary = strcat(binary,"0101");break;
				case '6': binary = strcat(binary,"0110");break;
				case '7': binary = strcat(binary,"0111");break;
				case '8': binary = strcat(binary,"1000");break;
				case '9': binary = strcat(binary,"1001");break;
				case 'a':
				case 'A': binary = strcat(binary,"1010");break;
				case 'b':
				case 'B': binary = strcat(binary,"1011");break;
				case 'c':
				case 'C': binary = strcat(binary,"1100");break;
				case 'd':
				case 'D': binary = strcat(binary,"1101");break;
				case 'e':
				case 'E': binary = strcat(binary,"1110");break;
		        case 'F':
		        case 'f':
		        	binary = strcat(binary,"1111");
		        	break;
		   	}
			i++;
		}
		if(strlen(token) == 1){
			binary = strcat(first_nibble,binary);
		}
		address = strcat(address,binary);
		token = strtok(NULL,":");
	}
	return address;
}

char* get_hex_char(char *x){
	if(strcmp(x,"0000")==0) return "0";
	if(strcmp(x,"0001")==0) return "1";
	if(strcmp(x,"0010")==0) return "2";
	if(strcmp(x,"0011")==0) return "3";
	if(strcmp(x,"0100")==0) return "4";
	if(strcmp(x,"0101")==0) return "5";
	if(strcmp(x,"0110")==0) return "6";
	if(strcmp(x,"0111")==0) return "7";
	if(strcmp(x,"1000")==0) return "8";
	if(strcmp(x,"1001")==0) return "9";
	if(strcmp(x,"1010")==0) return "A";
	if(strcmp(x,"1011")==0) return "B";
	if(strcmp(x,"1100")==0) return "C";
	if(strcmp(x,"1101")==0) return "D";
	if(strcmp(x,"1110")==0) return "E";
	if(strcmp(x,"1111")==0) return "F";
	return "";
}

char* toHEX(char *string){
	char* hex_string = calloc(17,sizeof(char));
	for(int i = 0;i<6;i++){
		char *byte = pluck(string,i*8,8);
		char *nibble_1 = pluck(byte,0,4);
		char *nibble_2 = pluck(byte,4,8);
		hex_string = strcat(hex_string,get_hex_char(nibble_1));
		hex_string = strcat(hex_string,get_hex_char(nibble_2));
		if(i != 5){
			hex_string = strcat(hex_string,":");
		}
	}
	return hex_string;
}


