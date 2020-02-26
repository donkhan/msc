#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(char **c,int no){
	int i;
	for(i = 0;i<no;i++){
		printf("%s\n",c[i]);
	}
}

int main(){
	char **c;
	int i = 0;int no = 10;
	c = (char **)malloc(sizeof(char *) * 10);
	for(i = 0;i<no;i++){
		c[i] = (char *) malloc(sizeof(char) * 10);
	}
	strcpy(c[0],"Madurai");
	strcpy(c[1],"Trichy");
	print(c,2);
}
