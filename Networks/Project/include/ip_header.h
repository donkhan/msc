#ifndef IP_HEADER
#define IP_HEADER
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct ip_header {
	unsigned int version :4;
	unsigned int ihl :4;
	unsigned int dscp :6;
	unsigned int ecn :2;
	unsigned int total_length :16;
	unsigned int identification :16;
	unsigned int flags :2;
	unsigned int fragment_offset :14;

	unsigned int ttl :8;
	unsigned int protocol :8;
	unsigned int header_checksum :16;

	char src[15];
	char dst[15];
};

struct ip_header* get_sample_ip_header();
struct ip_header* get_empty_ip_header();
int end_of_ip_header(struct ip_header *header);
char* encapsulate_ip_header(struct ip_header *ip_header);
struct ip_header* craft_ip_packet_header(int in);
struct ip_header* decapsulate_ip_header(char *c);
void print_ip_header(struct ip_header *ip_header);

#endif
