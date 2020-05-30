#include <stdlib.h>

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





