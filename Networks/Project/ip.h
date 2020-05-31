#include "ip_header.h"

struct ip_payload{
	struct ip_header* header;
	struct tcp_payload* data;
};

struct ip_payload* get_sample_ip_payload(){
	struct ip_payload* ip_payload = (struct ip_payload *) malloc(sizeof(struct ip_payload));
	struct tcp_payload* tcp_payload = get_sample_tcp_payload();
	ip_payload->header = get_sample_ip_header();
	ip_payload->data = tcp_payload;
	return ip_payload;
}

char* encapsulate_ip_payload(struct ip_payload* ip_payload){
	char* ip = encapsulate_ip_header(ip_payload->header);
	char *tcp = encapsulate_tcp_payload(ip_payload->data);
	printf("\nIP %s %lu ",ip,strlen(ip));
	printf("\nTCP %s %lu ",tcp,strlen(tcp));
	char *t = calloc(strlen(ip) + strlen(tcp),sizeof(char));
	for(int i = 0;i<strlen(ip);i++){
		t[i] = ip[i];
	}
	for(int i = strlen(ip);i<strlen(ip) + strlen(tcp);i++){
		t[i] = tcp[i - strlen(ip)];
	}
	return t;
}

struct ip_payload* decapsulate_ip_payload(char *c){
	struct ip_payload* payload = (struct ip_payload *)malloc(sizeof(struct ip_payload));
	payload->header = decapsulate_ip_header(c);
	int e = end_of_ip_header(payload->header);
	int total = strlen(c);
	char* data = pluck(c,e,total-e);
	payload->data = decapsulate_tcp_payload(data);
	return payload;
}


void print_ip_payload(struct ip_payload* payload){
	print_ip_header(payload->header);
	print_tcp_payload(payload->data);
}




