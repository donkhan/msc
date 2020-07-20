/*
 * Caesar.c
 *
 *  Created on: 20-Jul-2020
 *      Author: kkhan
 */

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "caesar.h"

char* encrypt(char* plain_text,int k){
	char* cipher_text = (char *)malloc(sizeof(char) * strlen(plain_text));
	for(int i = 0;i<strlen(plain_text);i++){
		int mod = (plain_text[i] - 'A' + k) % 26;
		cipher_text[i] = 'A' + mod;
	}
	return cipher_text;
}

char* decrypt(char* cipher_text,int k){
	char* plain_text = (char *)malloc(sizeof(char) * strlen(cipher_text));
	for(int i = 0;i<strlen(cipher_text);i++){
		int mod = (cipher_text[i] - 'A' - k) % 26;
		plain_text[i] = 'A' + mod;
	}
	return plain_text;
}

int main(){
	char i[10],*p,*c;
	int k;
	printf("Please Enter Plain Text:");
	scanf("%s",i);
	printf("Enter K: ");
	scanf("%d",&k);
	c = encrypt(i,k);
	printf("Cipher Text %s\n",c);
	p = decrypt(c,k);
	printf("Plain Text %s\n",p);
}

