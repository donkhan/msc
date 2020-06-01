#include<stdio.h>
#include<string.h>
#include "lib.h"
#include "tcp_header.h"
#include "tcp.h"
#include "udp_header.h"
#include "udp.h"
#include "ip_header.h"
#include "ip.h"
#include "eth_header.h"
#include "eth.h"

void tcp_test(){
	struct tcp_payload* tcp_payload = craft_tcp_payload(1);
	char* bs = encapsulate_tcp_payload(tcp_payload);
	print_tcp_payload(tcp_payload);
	print_bytes(bs,strlen(bs));
	tcp_payload = decapsulate_tcp_payload(bs);
	print_tcp_payload(tcp_payload);
}

void udp_test(){
	struct udp_payload* udp_payload = craft_udp_payload(1);
	char* bs = encapsulate_udp_payload(udp_payload);
	print_udp_payload(udp_payload);
	print_bytes(bs,strlen(bs));
	udp_payload = decapsulate_udp_payload(bs);
	print_udp_payload(udp_payload);
}

void udp_header_test(){
	struct udp_header* p = craft_udp_header(1);
	char* bs = encapsulate_udp_header(p);
	print_udp_header(p);
	print_bytes(bs,strlen(bs));
	p = decapsulate_udp_header(bs);
	print_udp_header(p);
}

void ip_header_test(){
	struct ip_header* pl = craft_ip_packet_header(1);
	char* bs = encapsulate_ip_header(pl);
	print_ip_header(pl);
	print_bytes(bs,strlen(bs));
	pl = decapsulate_ip_header(bs);
	print_ip_header(pl);
}

void tcp_header_test(){
	struct tcp_header* pl = craft_tcp_header(1);
	char* bs = encapsulate_tcp_header(pl);
	print_tcp_header(pl);
	print_bytes(bs,strlen(bs));
	pl = decapsulate_tcp_header(bs);
	print_tcp_header(pl);
}

void ip_test(){
	struct ip_payload* pl = craft_ip_payload(1,1);
	char* bs = encapsulate_ip_payload(pl);
	print_ip_payload(pl);
	print_bytes(bs,strlen(bs));
	pl = decapsulate_ip_payload(bs,1);
	print_ip_payload(pl);
}

void eth_header_test(){
	struct eth_header* pl = craft_eth_header(0);
	char* bs = encapsulate_eth_header(pl);
	print_eth_header(pl);
	print_bytes(bs,strlen(bs));
	pl = decapsulate_eth_header(bs);
	print_eth_header(pl);
}

void eth_test(){
	int option = 1;
	struct eth* pl = craft_eth(1,option);
	char* bs = encapsulate_eth(pl,option);
	print_eth(pl,option);
	print_bytes(bs,strlen(bs));
	pl = decapsulate_eth(bs,option);
	print_eth(pl,option);
}


int main(){
	eth_test();
}


