#include<stdio.h>
#include<string.h>
#include "lib.h"
#include "tcp.h"
#include "ip.h"

void printOption(char *message){
	printf("%s\nEnter Your Choice:  ",message);
}

void save(char* bs,char* ext){
	printOption("\nPress 1 to store the Binary Payload 2 to Skip Saving");
	int option = 1;
	scanf("%d",&option);
	if(option == 1){
		printf("Enter File Name: ");
		char file_name[15];
		scanf("%s",file_name);

		char *dir = "data/";
		printf("Directory %s\n",dir);

		char* f_name = strcat(file_name, ext);
		printf("File Name %s\n",f_name);

		FILE *fpr;
		fpr = fopen(file_name, "w");
		fputs(bs,fpr);
		fclose(fpr);
		printf("Wrote to the file %s ",file_name);
	}
}

char* read(char* ext){
	printf("Enter File Name: ");
	char file_name[15];
	scanf("%s",file_name);
	char* f_name = strcat(file_name, ext);
	printf("Reading from file %s\n",f_name);
	FILE *fp;
	fp = fopen(file_name, "r");
	fseek(fp, 0L, SEEK_END);
	int sz = ftell(fp);
	sz = sz + 1;
	fclose(fp);
	char* bs = malloc(sz);
	fp = fopen(file_name, "r");
	fgets(bs,sz,fp);
	fclose(fp);
	printf("Binary %s\n",bs);
	return bs;
}

void tcp_encapsulation(){
	struct tcp_payload* tcp_payload = get_sample_tcp_payload();
	char* bs = encapsulate_tcp_payload(tcp_payload);
	print_tcp_payload(tcp_payload);
	print_bytes(bs,strlen(bs));
	tcp_payload = decapsulate_tcp_payload(bs);
	print_tcp_payload(tcp_payload);
	save(bs,".tcp");
}

void ip_encapsulation(){
	struct ip_payload* ip_payload = get_sample_ip_payload();
	ip_payload->data->data = "FAZ";
	char* bs = encapsulate_ip_payload(ip_payload);
	print_ip_payload(ip_payload);
	print_bytes(bs,strlen(bs));
	ip_payload = decapsulate_ip_payload(bs);
	print_ip_payload(ip_payload);
	save(bs,".ip");
}

void tcp_decapsulation(){
	char* bs = read(".tcp");
	struct tcp_payload* tcp_payload = decapsulate_tcp_payload(bs);
	print_tcp_payload(tcp_payload);
}

void ip_decapsulation(){
	char* bs = read(".ip");
	struct ip_payload* ip_payload = decapsulate_ip_payload(bs);
	print_ip_payload(ip_payload);
}

int main(){
	int option;
	int flag = 1;
	while(flag){
		printOption("\n1-TCP Encapsulation \n2-TCP Decapsulation \n3-IP Encapsulation \n4-IP Decapsulation \n5-Quit.\n");
		scanf("%d",&option);
		printf("Selected Option %d\n",option);
		switch(option){
			case 1: tcp_encapsulation(); break;
			case 2: tcp_decapsulation(); break;
			case 3: ip_encapsulation(); break;
			case 4: ip_decapsulation(); break;
			case 5: flag = 0;
		}
	}
	return 1;
}
