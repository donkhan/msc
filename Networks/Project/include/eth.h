#ifndef LIBETH
#define LIBETH

struct eth{
	struct eth_header* header;
	struct ip* data;
};

struct eth* get_sample_eth(int option);
struct eth* craft_eth(int in,int option);
char* encapsulate_eth(struct eth* eth,int option);
struct eth* decapsulate_eth(char *c,int option);
void print_eth(struct eth* eth,int option);

#endif




