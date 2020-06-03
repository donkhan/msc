#include "tcp_header.h"
#include "lib.h"
#include "convert.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	if(in) {
		print_start("TCP Header Configuration");
		print_tcp_header(tcp_header);
		char option = get_option();
		if (option == 'c') {
			tcp_header->src_port = get_int_input_new("Source Port",
					tcp_header->src_port);
			tcp_header->dst_port = get_int_input_new("Destination Port",tcp_header->dst_port);
			tcp_header->seq_no = get_int_input_new("Sequence No",tcp_header->seq_no);
			tcp_header->ack_no = get_int_input_new("Acknowledgment No",tcp_header->ack_no);
			tcp_header->hlen = get_int_input_new("Header Length",tcp_header->hlen);
			tcp_header->window_size = get_int_input_new("Window Size",tcp_header->window_size);
			tcp_header->urg = get_int_input_new("Urgent Flag",tcp_header->urg);
			tcp_header->ack = get_int_input_new("Acknowledgment Flag",tcp_header->ack);
			tcp_header->psh = get_int_input_new("Push Flag",tcp_header->psh);
			tcp_header->rst = get_int_input_new("Reset Flag",tcp_header->rst);
			tcp_header->syn = get_int_input_new("Syn Flag",tcp_header->syn);
			tcp_header->fin = get_int_input_new("Fin Flag",tcp_header->fin);
			tcp_header->urgent_pointer = get_int_input_new("Urgent Pointer",tcp_header->urgent_pointer);
		}
		print_end("TCP Header Configuration");
	}
	return tcp_header;
}

char* encapsulate_tcp_header(struct tcp_header *tcp_header) {
	print_start("Encapsulating TCP Packet Header");
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
	print_bytes(tcp_packet);
	print_end("Encapsulating TCP Packet Header");
	gulp_go_ahead();
	return tcp_packet;
}

int end_of_header(struct tcp_header *header) {
	return 160 + (header->hlen * 32);
}

struct tcp_header* decapsulate_tcp_header(char *c) {
	struct tcp_header *tcp_header = (struct tcp_header*) malloc(
			sizeof(struct tcp_header));
	print_start("Decapsulating TCP Packet Header");
	print_bytes(c);
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
	print_end("Decapsulating TCP Packet Header");
	gulp_go_ahead();
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

