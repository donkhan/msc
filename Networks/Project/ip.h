#include "ip_header.h"

struct ip_payload{
	struct ip_header* header;
	char* data;
};

struct ip_payload* get_sample_ip_payload(){
	struct ip_payload* ip_payload = (struct ip_payload *) malloc(sizeof(struct ip_payload));
	ip_payload->header = get_sample_ip_header();
	return ip_payload;
}

char* encapsulate_ip_payload(struct ip_payload* ip_payload){
	char* bs = encapsulate_ip_header(ip_payload->header);
	/*
	char *data = ip_payload->data;
	int no_of_chars = strlen(data);
	for(int i = 0;i<no_of_chars;i++){
		bs = strcat(bs,int_to_binary(data[i],8));
	}
	*/
	return bs;
}

struct ip_payload* decapsulate_ip_payload(char *c){
	struct ip_payload* payload = (struct ip_payload *)malloc(sizeof(struct ip_payload));
	payload->header = decapsulate_ip_header(c);
	return payload;
}


void print_ip_payload(struct ip_payload* payload){
	print_ip_header(payload->header);
}




