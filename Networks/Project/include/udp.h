#ifndef XINC
#define XINC
struct udp{
	struct udp_header* header;
	char* data;
};

struct udp* get_sample_udp();
struct udp* craft_udp(int in);
char* encapsulate_udp(struct udp* udp);
struct udp* decapsulate_udp(char *c);
void print_udp(struct udp* payload);
  
#endif

