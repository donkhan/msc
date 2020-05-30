#include<stdio.h>
#include<string.h>

#include "tcp.h"



struct tcp* get_sample_tcp(){
	int i = 0;
	struct tcp* tcp = (struct tcp *) malloc(sizeof(struct tcp));
	tcp->src_port = 4;
	tcp->dst_port = 13;

	tcp->seq_no = 134000;
	tcp->ack_no = 45;

	tcp->hlen = 5;
	tcp->reserved = 0;
	tcp->window_size = 2345;
	tcp->urg = 1;
	tcp->ack = 1;
	tcp->psh = 1;
	tcp->rst = 0;
	tcp->syn = 1;
	tcp->fin = 0;

	tcp->tcp_checksum = 345;
	tcp->urgent_pointer = 234;


	tcp->options = malloc(sizeof(unsigned int) * tcp->hlen);
	for(i = 0;i<tcp->hlen;i++){
		tcp->options[i] = 0;
	}

	tcp->data = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return tcp;
}


int main(){

	struct tcp* tcp = get_sample_tcp();
	char* binary_string = encapsulate(tcp);
	print_tcp(tcp);
	printf("\nBinary Data ... \nLength %lu \nString %s\n",strlen(binary_string),binary_string);
	tcp = decapsulate(binary_string);
	print_tcp(tcp);
	return 1;
}
