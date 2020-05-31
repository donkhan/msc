#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef LIB_INC
#include "lib.h"
#endif

struct ip_header {
	/*
	unsigned int version : 4;
	unsigned int ihl : 4;
	unsigned int dscp : 6;
	unsigned int ecn: 2;
	unsigned int total_length : 16;
	unsigned int identification : 16;
	unsigned int flags : 2;
	unsigned int fragment_offset : 14;

	unsigned int ttl : 8;
	unsigned int protocol : 8;
	unsigned int header_checksum : 16;
	*/
	char source_address[15];
	//char dst_address[15];
};

struct ip_header* get_sample_ip_header(){
	struct ip_header* ip_header = (struct ip_header *) malloc(sizeof(struct ip_header));
	/*
	ip_header->version = 4;
	ip_header->ihl = 1;
	ip_header->dscp = 2;
	ip_header->ecn = 1;
	ip_header->total_length = 300;
	ip_header->identification = 16;
	ip_header->flags = 1;
	ip_header->fragment_offset = 23;

	ip_header->ttl  = 4;
	ip_header->protocol = 12;
	ip_header->header_checksum = 34;
	*/

	strcpy(ip_header->source_address,"192.168.1.4");
	//strcpy(ip_header->dst_address,"192.168.11.2");

	return ip_header;
}


char* encapsulate_ip_header(struct ip_header* ip_header){
	int size = 64;
	char *ip_packet = (char *)calloc(size,sizeof(char));
	/*
	ip_packet = strcat(ip_packet,int_to_binary(ip_header->version,4));
	ip_packet = strcat(ip_packet,int_to_binary(ip_header->ihl,4));
	ip_packet = strcat(ip_packet,int_to_binary(ip_header->dscp,6));
	ip_packet = strcat(ip_packet,int_to_binary(ip_header->ecn,2));
	ip_packet = strcat(ip_packet,int_to_binary(ip_header->total_length,16));

	ip_packet = strcat(ip_packet,int_to_binary(ip_header->identification,16));
	ip_packet = strcat(ip_packet,int_to_binary(ip_header->flags,2));
	ip_packet = strcat(ip_packet,int_to_binary(ip_header->fragment_offset,14));

	ip_packet = strcat(ip_packet,int_to_binary(ip_header->ttl,8));
	ip_packet = strcat(ip_packet,int_to_binary(ip_header->protocol,8));
	ip_packet = strcat(ip_packet,int_to_binary(ip_header->header_checksum,16));
	*/

	ip_packet = strcat(ip_packet,get_4_octets(ip_header->source_address));
	//ip_packet = strcat(ip_packet,get_4_octets(ip_header->dst_address));

	return ip_packet;
}


struct ip_header* decapsulate_ip_header(char *c){
	struct ip_header* ip_header = (struct ip_header *)malloc(sizeof(struct ip_header *));
	/*
	ip_header->version = fromBinary(pluck(c,0,4));
	ip_header->ihl = fromBinary(pluck(c,4,4));
	ip_header->dscp = fromBinary(pluck(c,8,6));
	ip_header->ecn = fromBinary(pluck(c,14,2));
	ip_header->total_length = fromBinary(pluck(c,16,16));

	ip_header->identification = fromBinary(pluck(c,32,16));
	ip_header->flags = fromBinary(pluck(c,48,2));
	ip_header->fragment_offset = fromBinary(pluck(c,50,14));

	ip_header->ttl = fromBinary(pluck(c,64,8));
	ip_header->protocol = fromBinary(pluck(c,72,8));
	ip_header->header_checksum = fromBinary(pluck(c,80,16));
	*/
	char *s = toIP(pluck(c,0,32));
	strcpy(ip_header->source_address,s);
	//strcpy(ip_header->dst_address,toIP(pluck(c,32,32)));

	return ip_header;
}

void print_ip_header(struct ip_header* ip_header){
	/*
	printf("\n Version %d",ip_header->version);
	printf("\n Internet Header Length %d",ip_header->ihl);
	printf("\n Differentiated Services Code Point %d",ip_header->dscp);
	printf("\n Explicit Congestion Notification %d",ip_header->ecn);
	printf("\n Total Length %d",ip_header->total_length);
	printf("\n Identification %d",ip_header->identification);
	printf("\n Flags %d",ip_header->flags);
	printf("\n Fragment Offset %d", ip_header->fragment_offset);
	printf("\n TTL %d", ip_header->ttl);
	printf("\n Protocol %d", ip_header->protocol);
	printf("\n Header Checksum %d", ip_header->header_checksum);

	printf("\n Source Address %s",ip_header->source_address);
	printf("\n Destination Address %s",ip_header->dst_address);
	*/
	printf("\n");

}
