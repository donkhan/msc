/*
 * Main.c
 *
 *  Created on: 20-Jul-2020
 *      Author: kkhan
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "caesar.h"

void test(){
	char i[20],*p,*c;
	int k;
	strcpy(i,"ABCDEF");
	k = 3;
	printf("Example Plain Text %s k %d",i,k);
	c = caesar_encryption(i,k);
	printf("Cipher Text %s\n",c);
	p = caesar_decryption(c,k);
	printf("After Decryption Plain Text %s\n",p);
}

void test_encryption(){
	char i[20],*c;
	int k;
	printf("Please Enter Plain Text:");
	scanf("%s",i);
	printf("Enter K: ");
	scanf("%d",&k);
	k = k % 26;
	printf("Encrypted Cipher Text %s\n",caesar_encryption(i,k));
}

void test_decryption(){
	char i[20],*p;
	int k;
	printf("Please Enter Cipher Text:");
	scanf("%s",i);
	printf("Enter K: ");
	scanf("%d",&k);
	k = k % 26;
	printf("Decrypted Plain Text %s\n",caesar_decryption(i,k));
}

int main(){


	int option;
	while(1){
		printf("Options 1-Encrypt 2-Decrypt 3-Test 4-Quit \n");
		scanf("%d",&option);
		switch(option){
			case 1: test_encryption();break;
			case 2: test_decryption();break;
			case 3: test();break;
			case 4: exit(1); break;
		}
	}


}
