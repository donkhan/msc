#include "caesar.h"
#include <stdlib.h>
#include <string.h>

char* caesar_encryption(char* plain_text,int k){
	char* cipher_text = (char *)malloc(sizeof(char) * strlen(plain_text));
	for(int i = 0;i<strlen(plain_text);i++){
		char p = plain_text[i];
		if(p >= 'A' && p <='Z'){
			cipher_text[i] = 'A' + (p - 65 + k) % 26;
		}
		else{
			cipher_text[i] = plain_text[i];
		}
	}
	return cipher_text;
}

char* caesar_decryption(char* cipher_text,int k){
	char* plain_text = (char *)malloc(sizeof(char) * strlen(cipher_text));
	for(int i = 0;i<strlen(cipher_text);i++){
		char c = cipher_text[i];
		if(c >= 'A' && c <= 'Z'){
			c = c - 65 - k;
			while(c < 0){
				c = c + 26;
			}
			plain_text[i] = 'A' + c % 26;
		}else{
			plain_text[i] = cipher_text[i];
		}
	}
	return plain_text;
}
