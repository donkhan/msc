#ifndef LIBETH_HEADER
#define LIBETH_HEADER
#include <stdio.h>
#include <string.h>

struct eth_header {
	char *src_mac;
	char *dst_mac;

};

struct eth_header* get_sample_eth_header();
struct eth_header* craft_eth_header(int in);
char* encapsulate_eth_header(struct eth_header* eth_header);
int end_of_eth_header(struct eth_header* header);
struct eth_header* decapsulate_eth_header(char *c);
void print_eth_header(struct eth_header* eth_header);
#endif


