#include <stdio.h>
#include <string.h>

struct eth_header {
	char *src_mac;
	char *dst_mac;

};

struct eth_header* get_sample_eth_header(){
	struct eth_header* eth_header = (struct eth_header *) malloc(sizeof(struct eth_header));
	eth_header->src_mac = calloc(17,sizeof(char));
	eth_header->dst_mac = calloc(17,sizeof(char));
	strcpy(eth_header->src_mac , "FF:FF:FF:FF:FF:12");
	strcpy(eth_header->dst_mac , "4F:1F:CD:AB:FF:12");
	return eth_header;
}

struct eth_header* craft_eth_header(int in){
	struct eth_header* eth_header = get_sample_eth_header();
	if(in){
		print_start("ETH HEADER CONFIGURATION");
		printf("Source MAC...");
		scanf("%s",eth_header->src_mac);
		printf("Destination MAC...");
		scanf("%s",eth_header->dst_mac);
		print_end("ETH HEADER CONFIGURATION");
	}
	return eth_header;
}

char* encapsulate_eth_header(struct eth_header* eth_header){
	int size = 96;
	char *eth_packet = (char *)calloc(size,sizeof(char));
	eth_packet = strcat(eth_packet, get_6_octets(eth_header->src_mac));
	eth_packet = strcat(eth_packet, get_6_octets(eth_header->dst_mac));
	return eth_packet;
}

int end_of_eth_header(struct eth_header* header){
	return 96;
}

struct eth_header* decapsulate_eth_header(char *c){
	struct eth_header* eth_header = (struct eth_header *)malloc(sizeof(struct eth_header));
	eth_header->src_mac = calloc(17,sizeof(char));
	eth_header->dst_mac = calloc(17,sizeof(char));
	strcpy(eth_header->src_mac, toHEX((char*) pluck(c, 0, 48)));
	strcpy(eth_header->dst_mac, toHEX((char*) pluck(c, 48, 48)));
	return eth_header;
}

void print_eth_header(struct eth_header* eth_header){
	print_start("ETH HEADER");
	printf("\nSource MAC %s",eth_header->src_mac);
	printf("\nDestination MAC %s",eth_header->dst_mac);
	print_end("ETH HEADER");
	printf("\n");
}



