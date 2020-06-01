#include <stdio.h>
#include <string.h>
#include "lib.h"
#include "tcp_header.h"
#include "tcp.h"
#include "udp_header.h"
#include "udp.h"
#include "ip_header.h"
#include "ip.h"
#include "eth_header.h"
#include "eth.h"

void printOption(char *message) {
	printf("%s\nEnter Your Choice:  ", message);
}

int get_transport_option(){
	int option;
	printf("Enter the Transport Layer: \n1-UDP 2-TCP\n");
	scanf("%d",&option);
	return option;
}

char* get_file_name(char* ext) {
	printf("Enter File Name: ");
	char file_name[15];
	scanf("%s", file_name);
	char *dir = "data/";
	printf("Directory %s\n", dir);

	char *f_name = malloc(strlen(dir) + strlen(file_name) + strlen(ext));
	f_name = strcat(f_name, dir);
	f_name = strcat(f_name, file_name);
	f_name = strcat(f_name, ext);
	printf("File Name %s\n", f_name);
	return f_name;
}

void save(char *bs, char *ext) {
	printOption(
			"\nPress 1 to store the Binary Payload \n"
			"Press 2 to Skip Saving");
	int option = 1;
	scanf("%d", &option);
	if (option == 1) {
		char* f_name = get_file_name(ext);
		FILE *fpr;
		fpr = fopen(f_name, "w");
		fputs(bs, fpr);
		fclose(fpr);
		printf("Wrote to the file %s ", f_name);
	}
}

char* read(char *ext) {
	char* file_name = get_file_name(ext);
	FILE *fp;
	fp = fopen(file_name, "r");
	fseek(fp, 0L, SEEK_END);
	int sz = ftell(fp);
	sz = sz + 1;
	fclose(fp);
	char *bs = malloc(sz);
	fp = fopen(file_name, "r");
	fgets(bs, sz, fp);
	fclose(fp);
	print_bytes(bs,strlen(bs));
	return bs;
}


void tcp_encapsulation() {
	struct tcp *tcp = get_sample_tcp();
	print_tcp(tcp);
	char *bs = encapsulate_tcp(tcp);
	print_bytes(bs, strlen(bs));
	tcp = decapsulate_tcp(bs);
	print_tcp(tcp);
	save(bs, ".tcp");
}

void udp_encapsulation() {
	struct udp *udp = get_sample_udp();
	char *bs = encapsulate_udp(udp);
	print_udp(udp);
	print_bytes(bs, strlen(bs));
	udp = decapsulate_udp(bs);
	print_udp(udp);
	save(bs, ".udp");
}

void udp_decapsulation() {
	char *bs = read(".udp");
	struct udp *udp = decapsulate_udp(bs);
	print_udp(udp);
}

void ip_encapsulation() {
	int option = get_transport_option();
	struct ip *ip = get_sample_ip(option);
	char *bs = encapsulate_ip(ip);
	print_ip(ip);
	print_bytes(bs, strlen(bs));
	ip = decapsulate_ip(bs,option);
	print_ip(ip);
	save(bs, ".ip");
}

void eth_encapsulation() {
	int option = get_transport_option();
	struct eth *eth = get_sample_eth(option);
	char *bs = encapsulate_eth(eth,option);
	print_eth(eth,option);
	print_bytes(bs, strlen(bs));
	eth = decapsulate_eth(bs,option);
	print_eth(eth,option);
	save(bs, ".eth");
}

void eth_decapsulation() {
	int option = get_transport_option();
	char *bs = read(".eth");
	struct eth *eth = decapsulate_eth(bs,option);
	print_eth(eth,option);
}

void tcp_decapsulation() {
	char *bs = read(".tcp");
	struct tcp *tcp = decapsulate_tcp(bs);
	print_tcp(tcp);
}

void ip_decapsulation() {
	int option = get_transport_option();
	char *bs = read(".ip");
	struct ip *ip = decapsulate_ip(bs,option);
	print_ip(ip);
}

void craft(){
	printf("\nCrafting...\n");
	int option = get_transport_option();
	struct eth* eth = craft_eth(option,1);
	print_eth(eth,option);
	char *bs = encapsulate_eth(eth,1);
	print_bytes(bs, strlen(bs));
	eth = decapsulate_eth(bs,option);
	print_eth(eth,option);
	save(bs, ".eth");
}


int main() {
	int option;
	int flag = 1;
	while (flag) {
		printOption("\n1-TCP Encapsulation "
				"\n2-TCP Decapsulation "
				"\n3-UDP Encapsulation"
				"\n4-UDP Decapsulation "
				"\n5-IP Encapsulation"
				"\n6-IP Decapsulation "
				"\n7-Craft"
				"\n8-Eth Encapsulation"
				"\n9-Eth Decapsulation"
				"\n10-Quit."
				"\n");
		scanf("%d", &option);
		printf("Selected Option %d\n", option);
		switch (option) {
		case 1:
			tcp_encapsulation();
			break;
		case 2:
			tcp_decapsulation();
			break;
		case 3:
			udp_encapsulation();
			break;
		case 4:
			udp_decapsulation();
			break;
		case 5:
			ip_encapsulation();
			break;
		case 6:
			ip_decapsulation();
			break;
		case 7:
			craft();
			break;
		case 8:
			eth_encapsulation();
			break;
		case 9:
			eth_decapsulation();
			break;
		case 10:
			printf("Quitting the Demo... Bye\n");
			flag = 0;
		}
	}
	return 1;
}
