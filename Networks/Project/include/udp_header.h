#ifndef UDP_HEADER
#define UDP_HEADER

struct udp_header {
	unsigned int src_port : 16;
    unsigned int dst_port : 16;
    unsigned int length : 16;
    unsigned int checksum : 16;
};

struct udp_header* get_sample_udp_header();
struct udp_header* craft_udp_header(int in);
char* encapsulate_udp_header(struct udp_header* udp_header);
int end_of_udp_header(struct udp_header* header);
struct udp_header* decapsulate_udp_header(char *c);
void print_udp_header(struct udp_header* udp_header);


#endif
