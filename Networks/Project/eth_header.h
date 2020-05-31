#include <stdio.h>
#include <string.h>

struct eth_header {
	unsigned char *src_mac;
	//unsigned char *dst_mac;

};

struct eth_header* get_sample_eth_header(){
	struct eth_header* eth_header = (struct eth_header *) malloc(sizeof(struct eth_header));
	eth_header->src_mac = calloc(17,sizeof(char));
	strcpy(eth_header->src_mac,"80:00:20:7A:3F;3E")
	return eth_header;
}


char* encapsulate_eth_header(struct eth_header* eth_header){
	int size = 32;
	char *eth_packet = (char *)calloc(size,sizeof(char));
	return eth_packet;
}

int end_of_eth_header(struct udp_header* header){
	return 64;
}

struct eth_header* decapsulate_eth_header(char *c){
	struct eth_header* eth_header = (struct udp_header *)malloc(sizeof(struct udp_header));
	return udp_header;
}

void print_eth_header(struct eth_header* eth_header){
	print_start("ETH");
	printf("\nSource MAC %s",eth_header->src_mac);
	print_end("ETH");
	printf("\n");
}

