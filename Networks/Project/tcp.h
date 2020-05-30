#include <stdio.h> 
#include <string.h>

#include "lib.h"
  
struct tcp { 
	unsigned int src_port : 16;
    unsigned int dst_port : 16;

    unsigned int seq_no : 32;

    unsigned int ack_no : 32;

	unsigned int hlen : 4;
	unsigned int reserved : 6;
	unsigned int urg : 1;
	unsigned int ack : 1;
	unsigned int psh : 1;
	unsigned int rst : 1;
	unsigned int syn : 1;
	unsigned int fin : 1;
	unsigned int window_size : 16;
	

	unsigned int tcp_checksum : 16;
	unsigned int urgent_pointer : 16;

	//The number of 32 bit words in the TCP Header.
	unsigned int* options;

	char* data;
	
}; 


  
char* encapsulate(struct tcp* tcp){

	char *s;
	int fixed_header_size = 160;
	int variable_header_size = (tcp->hlen * 32) + 1;
	int data_size = sizeof(tcp->data);
	int size = fixed_header_size + variable_header_size + 1 + (data_size * 8);
	printf("Header Length %d Options Length %d Data Length %d Total Length %d\n",fixed_header_size,
			variable_header_size,(data_size * 8),size);

	char *tcp_packet = malloc(size);
	append(int_to_binary(tcp->src_port,16),tcp_packet,0,16);
	append(int_to_binary(tcp->dst_port,16),tcp_packet,16,16);
	append(int_to_binary(tcp->seq_no,32),tcp_packet,32,32);
	append(int_to_binary(tcp->ack_no,32),tcp_packet,64,32);
	append(int_to_binary(tcp->hlen,4),tcp_packet,96,4);
	append(int_to_binary(tcp->reserved,6),tcp_packet,100,6);
	append(int_to_binary(tcp->urg,1),tcp_packet,106,1);
	append(int_to_binary(tcp->ack,1),tcp_packet,107,1);
	append(int_to_binary(tcp->psh,1),tcp_packet,108,1);
	append(int_to_binary(tcp->rst,1),tcp_packet,109,1);
	append(int_to_binary(tcp->syn,1),tcp_packet,110,1);

	append(int_to_binary(tcp->fin,1),tcp_packet,111,1);
	append(int_to_binary(tcp->window_size,16),tcp_packet,112,16);

	append(int_to_binary(tcp->tcp_checksum,16),tcp_packet,128,16);
	append(int_to_binary(tcp->urgent_pointer,16),tcp_packet,144,16);

	char *options = int_star_to_binary(tcp->options,tcp->hlen);
	append(options,tcp_packet,160,strlen(options));

	for(int i = 0;i<strlen(tcp->data);i++){
		tcp_packet = strcat(tcp_packet,int_to_binary(tcp->data[i],8));
	}
	return tcp_packet;
}

struct tcp* decapsulate(char *c){
	struct tcp* tcp = (struct tcp *)malloc(sizeof(struct tcp *));
	char *s;
	int i;

	tcp->src_port = fromBinary(pluck(c,0,16));
	tcp->dst_port = fromBinary(pluck(c,16,16));
	tcp->seq_no   =   fromBinary(pluck(c,32,32));
	tcp->ack_no   =   fromBinary(pluck(c,64,32));

	tcp->hlen     =   fromBinary(pluck(c,96,4));
	tcp->reserved     =   fromBinary(pluck(c,100,6));

	tcp->urg = fromBinary(pluck(c,106,1));
	tcp->ack = fromBinary(pluck(c,107,1));
	tcp->psh = fromBinary(pluck(c,108,1));
	tcp->rst = fromBinary(pluck(c,109,1));
	tcp->syn = fromBinary(pluck(c,110,1));
	tcp->fin = fromBinary(pluck(c,111,1));
	tcp->window_size     =   fromBinary(pluck(c,112,16));

	tcp->tcp_checksum     =   fromBinary(pluck(c,128,16));
	tcp->urgent_pointer    =   fromBinary(pluck(c,144,16));
	int offset = 160;
	tcp->options = malloc(sizeof(unsigned int) * tcp->hlen);
	for(i = 0;i<tcp->hlen;i++){
		tcp->options[i] = fromBinary(pluck(c,160 + (i*32),32));
		offset = offset + 32;
	}

	char* data = pluck(c,offset,strlen(c)-offset);
	int no_of_chars = strlen(data)/8;
	tcp->data = malloc(sizeof(char)*no_of_chars);
	printf("No of characters %d\n",no_of_chars);

	for(int i = 0;i<no_of_chars;i++){
		char d = fromBinary(pluck(data,i*8,8));
		//printf("%c\n",d);
		tcp->data[i] = d;
	}

	return tcp;
}

void print_tcp(struct tcp* tcp){

	printf("\nSource Port %d",tcp->src_port);
	printf("\nDestination Port %d",tcp->dst_port);
	printf("\nSequence No %d",tcp->seq_no);
	printf("\nAck No %d",tcp->ack_no);
	printf("\nHeader-Length (Data OffSet) %d",tcp->hlen);
	printf("\nReserved %d",tcp->reserved);
	printf("\nWindow Size %d",tcp->window_size);
	printf("\nFlags Urg %d Ack %d Psh %d Rst %d Syn %d Fin %d",tcp->urg,tcp->ack,
			tcp->psh,tcp->rst,tcp->syn,tcp->fin);

	printf("\nCheck Sum %d",tcp->tcp_checksum);
	printf("\nUrgent Pointer %d",tcp->urgent_pointer);
	printf("\nSize of Options %lu",sizeof(tcp->options));
	printf("\nData  %s ",tcp->data);

	printf("\n");

}


