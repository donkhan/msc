#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void print_bytes(char *s,int length){
	int bytes = 0;
	printf("\nBinary: %s\n",s);
	printf("Octet Split \n");
	for(int i = 0;i<length;i++){
		if(i%8 == 0 && i != 0){
			printf(",");
			bytes = bytes + 1;
		}
		printf("%c",s[i]);
	}
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
		if(i != 3){
			x[k] = '.';
			k = k + 1;
		}
	}

	address = malloc(sizeof(strlen(x)-1));
	for(int i = 0;i<strlen(x);i++){
		address[i] = x[i];
	}
	return address;
}

void print_start(char* header){
	printf("\n************** %s ***************",header);
	printf("******************************************");
}

void print_end(char* header){
	printf("\n************** End of %s ***************",header);
	printf("*************************************************");
}




