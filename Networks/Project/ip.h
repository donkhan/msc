#ifndef IP
#define IP

struct ip{
	struct ip_header* header;
	void* data;
	int option;
};

struct ip* get_sample_ip(int option);
struct ip* craft_ip(int option,int in);
char* encapsulate_ip(struct ip* ip);
struct ip* decapsulate_ip(char *c,int option);
void print_ip(struct ip* payload);

#endif


