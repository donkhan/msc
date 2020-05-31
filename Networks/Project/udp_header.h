#include <stdio.h>
#include <string.h>

struct udp_header {
	unsigned int src_port : 16;
    unsigned int dst_port : 16;
    unsigned int length : 16;
    unsigned int checksum : 16;
};

struct udp_header* get_sample_udp_header(){
	struct udp_header* udp_header = (struct udp_header *) malloc(sizeof(struct udp_header));
	udp_header->src_port = 41;
	udp_header->dst_port = 132;
	udp_header->length = 56;
	udp_header->checksum = 123;

	return udp_header;
}


char* encapsulate_udp_header(struct udp_header* udp_header){
	int size = 32;
	char *udp_packet = (char *)calloc(size,sizeof(char));
	udp_packet = strcat(udp_packet,int_to_binary(udp_header->src_port,16));
	udp_packet = strcat(udp_packet,int_to_binary(udp_header->dst_port,16));
	udp_packet = strcat(udp_packet,int_to_binary(udp_header->length,16));
	udp_packet = strcat(udp_packet,int_to_binary(udp_header->checksum,16));
	return udp_packet;
}

int end_of_udp_header(struct udp_header* header){
	return 64;
}

struct udp_header* decapsulate_udp_header(char *c){
	struct udp_header* udp_header = (struct udp_header *)malloc(sizeof(struct udp_header));
	udp_header->src_port = fromBinary(pluck(c,0,16));
	udp_header->dst_port = fromBinary(pluck(c,16,16));
	udp_header->length = fromBinary(pluck(c,32,16));
	udp_header->checksum = fromBinary(pluck(c,48,16));

	return udp_header;
}

void print_udp_header(struct udp_header* udp_header){
	print_start("UDP");
	printf("\nSource Port %d",udp_header->src_port);
	printf("\nDestination Port %d",udp_header->dst_port);
	printf("\nLength %d",udp_header->dst_port);
	printf("\nChecksum %d",udp_header->dst_port);
	print_end("UDP");
	printf("\n");
}

