#include "udp_header.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct udp_header* get_sample_udp_header(){
	struct udp_header* udp_header = (struct udp_header *) malloc(sizeof(struct udp_header));
	udp_header->src_port = 41;
	udp_header->dst_port = 132;
	udp_header->length = 56;
	udp_header->checksum = 123;
	return udp_header;
}

struct udp_header* craft_udp_header(int in){
	struct udp_header* udp_header = get_sample_udp_header();
	if(in == 1){
		print_start("UDP Header Configuration");
		print_udp_header(udp_header);
		char option = get_option();
		if (option == 'c') {
			udp_header->src_port = get_int_input_between("Source Port",udp_header->src_port,0,65536);
			udp_header->dst_port = get_int_input_between("Destination Port",udp_header->dst_port,0,65536);		}
		print_end("UDP Header Configuration");
	}
	return udp_header;
}

char* encapsulate_udp_header(struct udp_header* udp_header){
	int size = 32;
	char *udp_packet = (char *)calloc(size,sizeof(char));
	print_start("Encapsulating UDP Packet Header");
	udp_packet = strcat(udp_packet,int_to_binary(udp_header->src_port,16));
	udp_packet = strcat(udp_packet,int_to_binary(udp_header->dst_port,16));
	udp_packet = strcat(udp_packet,int_to_binary(udp_header->length,16));
	udp_packet = strcat(udp_packet,int_to_binary(udp_header->checksum,16));
	print_bytes(udp_packet);
	print_end("Encapsulating UDP Packet Header");
	gulp_go_ahead();
	return udp_packet;
}

int end_of_udp_header(struct udp_header* header){
	return 64;
}

struct udp_header* decapsulate_udp_header(char *c){
	print_start("Decapsulating UDP Header");
	print_bytes(c);
	struct udp_header* udp_header = (struct udp_header *)malloc(sizeof(struct udp_header));
	udp_header->src_port = fromBinary(pluck(c,0,16));
	udp_header->dst_port = fromBinary(pluck(c,16,16));
	udp_header->length = fromBinary(pluck(c,32,16));
	udp_header->checksum = fromBinary(pluck(c,48,16));
	print_end("Decapsulating UDP Header");
	gulp_go_ahead();
	return udp_header;
}

void print_udp_header(struct udp_header* udp_header){
	print_start("UDP Header");
	printf("\nSource Port %d",udp_header->src_port);
	printf("\nDestination Port %d",udp_header->dst_port);
	printf("\nLength %d",udp_header->length);
	printf("\nChecksum %d",udp_header->checksum);
	print_end("UDP Header");
	printf("\n");
}
