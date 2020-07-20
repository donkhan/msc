/*
 * Caesar.c
 *
 *  Created on: 20-Jul-2020
 *      Author: kkhan
 */


#include<string.h>
#include<stdio.h>
#include<stdlib.h>

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


void test_encryption(){
	printf("%s %s\n", "ABC",encrypt("ABC",3));
	printf("%s %s\n", "XYZ",encrypt("XYZ",3));
	printf("%s %s\n", "HELLOW WORLD",encrypt("HELLOW WORLD",3));
}


void test_decryption(){
	printf("%s %s\n", "DEF",decrypt("DEF",3));
}

void test(){
	char* C = encrypt("HELLOWWORLD",3);
	printf("Cipher Text %s\n",C);
	char* P = decrypt(C,3);
	printf("Plain Text %s\n",P);

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
