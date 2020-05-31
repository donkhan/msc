#include<stdio.h>
#include<string.h>
#include "lib.h"
#include "tcp_header.h"
#include "tcp.h"
#include "udp_header.h"
#include "udp.h"
#include "ip_header.h"
#include "ip.h"



void tcp_test(){
	struct tcp_payload* tcp_payload = craft_tcp_payload(0);
	char* bs = encapsulate_tcp_payload(tcp_payload);
	print_tcp_payload(tcp_payload);
	print_bytes(bs,strlen(bs));
	tcp_payload = decapsulate_tcp_payload(bs);
	print_tcp_payload(tcp_payload);
}

void udp_test(){
	struct udp_payload* udp_payload = craft_udp_payload(0);
	char* bs = encapsulate_udp_payload(udp_payload);
	print_udp_payload(udp_payload);
	print_bytes(bs,strlen(bs));
	udp_payload = decapsulate_udp_payload(bs);
	print_udp_payload(udp_payload);
}

void udp_header_test(){
	struct udp_header* p = craft_udp_header(0);
	char* bs = encapsulate_udp_header(p);
	print_udp_header(p);
	print_bytes(bs,strlen(bs));
	p = decapsulate_udp_header(bs);
	print_udp_header(p);
}



int main(){
	udp_header_test();
}


