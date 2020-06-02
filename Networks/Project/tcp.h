#ifndef TCP
#define TCP
struct tcp{
	struct tcp_header* header;
	void* data;
};

struct tcp* get_sample_tcp();
struct tcp* craft_tcp(int in);
char* encapsulate_tcp(struct tcp* tcp);
struct tcp* decapsulate_tcp(char *c);
void print_tcp(struct tcp* payload);

#endif
