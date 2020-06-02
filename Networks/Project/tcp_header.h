#ifndef TCP_HEADER
#define TCP_HEADER
#include <stdio.h>
#include <string.h>

struct tcp_header {
	unsigned int src_port :16;
	unsigned int dst_port :16;

	unsigned int seq_no :32;

	unsigned int ack_no :32;

	unsigned int hlen :4;
	unsigned int reserved :6;
	unsigned int urg :1;
	unsigned int ack :1;
	unsigned int psh :1;
	unsigned int rst :1;
	unsigned int syn :1;
	unsigned int fin :1;
	unsigned int window_size :16;
	unsigned int tcp_checksum :16;
	unsigned int urgent_pointer :16;
	//The number of 32 bit words in the TCP Header.
	unsigned int *options;
};

struct tcp_header* get_sample_tcp_header();
struct tcp_header* craft_tcp_header(int in);
char* encapsulate_tcp_header(struct tcp_header *tcp_header);
int end_of_header(struct tcp_header *header);
struct tcp_header* decapsulate_tcp_header(char *c);
void print_tcp_header(struct tcp_header *tcp_header);

#endif
