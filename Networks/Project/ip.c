#include "ip.h"
#include "lib.h"
#include "tcp.h"

struct ip* decapsulate_ip(char *c){
	struct ip* ip = (struct ip *)malloc(sizeof(struct ip *));
	ip->version = fromBinary(pluck(c,0,4));
	return ip;
}

void print_ip(struct ip* ip){
	printf("Version %d ",ip->version);
	printf("\n");
}

struct ip* get_sample_ip(){
	struct ip* ip = (struct ip *) malloc(sizeof(struct ip));
	ip->version = 4;
	return ip;
}

char* encapsulate_ip(struct ip* ip){
	int fixed_header_size = 4;
	char *ip_packet = malloc(fixed_header_size + strlen(ip->data));
	append(int_to_binary(ip->version,4),ip_packet,0,4);
	printf("%s %lu\n",ip->data,strlen(ip->data));
	//ip_packet = strcat(ip_packet,ip->data);
	//printf("IP Packet %s\n",ip_packet);
	return ip_packet;
}

void ip_test(){
	struct ip* ip = get_sample_ip();
	struct tcp* tcp = get_sample_tcp();
	ip->data = encapsulate_tcp(tcp);
	char* binary_string = encapsulate_ip(ip);
	print_ip(ip);
	ip = decapsulate_ip(binary_string);
	print_ip(ip);
}


int main(){
	ip_test();
	return 1;
}
