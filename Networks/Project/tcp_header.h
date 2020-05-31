#include <stdio.h>
#include <string.h>

struct tcp_header {
	unsigned int src_port :16;
	unsigned int dst_port :16;

	unsigned int seq_no :32;

	unsigned int ack_no :32;

	unsigned int hlen :4;
	unsigned int reserved :6;
	unsigned int urg :1;
	unsigned int ack :1;
	unsigned int psh :1;
	unsigned int rst :1;
	unsigned int syn :1;
	unsigned int fin :1;
	unsigned int window_size :16;
	unsigned int tcp_checksum :16;
	unsigned int urgent_pointer :16;
	//The number of 32 bit words in the TCP Header.
	unsigned int *options;
};

struct tcp_header* get_sample_tcp_header() {
	struct tcp_header *tcp_header = (struct tcp_header*) malloc(
			sizeof(struct tcp_header));
	tcp_header->src_port = 4;
	tcp_header->dst_port = 13;

	tcp_header->seq_no = 134000;
	tcp_header->ack_no = 45;

	tcp_header->hlen = 5;
	tcp_header->reserved = 0;
	tcp_header->window_size = 345;
	tcp_header->urg = 1;
	tcp_header->ack = 1;
	tcp_header->psh = 1;
	tcp_header->rst = 0;
	tcp_header->syn = 1;
	tcp_header->fin = 0;

	tcp_header->tcp_checksum = 345;
	tcp_header->urgent_pointer = 234;

	tcp_header->options = calloc(tcp_header->hlen, sizeof(int));
	for (int i = 0; i < tcp_header->hlen; i++) {
		tcp_header->options[i] = i + 45;
	}
	return tcp_header;
}

struct tcp_header* craft_tcp_header(int in) {
	struct tcp_header *tcp_header = get_sample_tcp_header();
	if (in) {
		print_start("TCP Header Configuration");
		int port;
		printf("\nEnter Source Port ");
		scanf("%d", &port);
		tcp_header->src_port = port;
		printf("\nEnter Destination Port ");
		scanf("%d", &port);
		tcp_header->dst_port = port;
		print_end("TCP Header Configuration");
	}
	return tcp_header;
}

char* encapsulate_tcp_header(struct tcp_header *tcp_header) {
	int size = 160 + (tcp_header->hlen * 32);
	char *tcp_packet = (char*) calloc(size, sizeof(char));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->src_port, 16));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->dst_port, 16));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->seq_no, 32));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->ack_no, 32));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->hlen, 4));
	tcp_packet = strcat(tcp_packet, "000000");
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->urg, 1));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->ack, 1));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->psh, 1));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->rst, 1));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->syn, 1));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->fin, 1));
	tcp_packet = strcat(tcp_packet, int_to_binary(tcp_header->window_size, 16));
	tcp_packet = strcat(tcp_packet,
			int_to_binary(tcp_header->tcp_checksum, 16));
	tcp_packet = strcat(tcp_packet,
			int_to_binary(tcp_header->urgent_pointer, 16));
	for (int i = 0; i < tcp_header->hlen; i++) {
		tcp_packet = strcat(tcp_packet,
				int_to_binary(tcp_header->options[i], 32));
	}
	return tcp_packet;
}

int end_of_header(struct tcp_header *header) {
	return 160 + (header->hlen * 32);
}

struct tcp_header* decapsulate_tcp_header(char *c) {
	struct tcp_header *tcp_header = (struct tcp_header*) malloc(
			sizeof(struct tcp_header));
	tcp_header->src_port = fromBinary(pluck(c, 0, 16));
	tcp_header->dst_port = fromBinary(pluck(c, 16, 16));
	tcp_header->seq_no = fromBinary(pluck(c, 32, 32));
	tcp_header->ack_no = fromBinary(pluck(c, 64, 32));
	tcp_header->hlen = fromBinary(pluck(c, 96, 4));
	tcp_header->reserved = fromBinary(pluck(c, 100, 6));
	tcp_header->urg = fromBinary(pluck(c, 106, 1));
	tcp_header->ack = fromBinary(pluck(c, 107, 1));
	tcp_header->psh = fromBinary(pluck(c, 108, 1));
	tcp_header->rst = fromBinary(pluck(c, 109, 1));
	tcp_header->syn = fromBinary(pluck(c, 110, 1));
	tcp_header->fin = fromBinary(pluck(c, 111, 1));
	tcp_header->window_size = fromBinary(pluck(c, 112, 16));
	tcp_header->tcp_checksum = fromBinary(pluck(c, 128, 16));
	tcp_header->urgent_pointer = fromBinary(pluck(c, 144, 16));
	tcp_header->options = calloc(tcp_header->hlen, sizeof(int));
	for (int i = 0; i < tcp_header->hlen; i++) {
		tcp_header->options[i] = fromBinary(pluck(c, 160 + (i * 32), 32));
	}
	return tcp_header;
}

void print_tcp_header(struct tcp_header *tcp_header) {
	print_start("TCP");
	printf("\nSource Port %d", tcp_header->src_port);
	printf("\nDestination Port %d", tcp_header->dst_port);
	printf("\nSequence No %d", tcp_header->seq_no);
	printf("\nAck No %d", tcp_header->ack_no);
	printf("\nHeader-Length (Data OffSet) %d", tcp_header->hlen);
	printf("\nReserved %d", tcp_header->reserved);
	printf("\nFlags Urg %d Ack %d Psh %d Rst %d Syn %d Fin %d", tcp_header->urg,
			tcp_header->ack, tcp_header->psh, tcp_header->rst, tcp_header->syn,
			tcp_header->fin);
	printf("\nWindow Size %d", tcp_header->window_size);
	printf("\nCheck Sum %d", tcp_header->tcp_checksum);
	printf("\nUrgent Pointer %d", tcp_header->urgent_pointer);
	for (int i = 0; i < tcp_header->hlen; i++) {
		printf("\nOptions %d %d", i, tcp_header->options[i]);
	}
	print_end("TCP");
	printf("\n");
}

