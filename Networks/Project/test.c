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
	struct tcp* tcp = craft_tcp(1);
	char* bs = encapsulate_tcp(tcp);
	print_tcp(tcp);
	print_bytes(bs);
	tcp = decapsulate_tcp(bs);
	print_tcp(tcp);
}

void udp_test(){
	struct udp* udp = craft_udp(1);
	char* bs = encapsulate_udp(udp);
	print_udp(udp);
	print_bytes(bs);
	udp = decapsulate_udp(bs);
	print_udp(udp);
}

void udp_header_test(){
	struct udp_header* p = craft_udp_header(1);
	char* bs = encapsulate_udp_header(p);
	print_udp_header(p);
	print_bytes(bs);
	p = decapsulate_udp_header(bs);
	print_udp_header(p);
}

void ip_header_test(){
	struct ip_header* pl = craft_ip_packet_header(1);
	char* bs = encapsulate_ip_header(pl);
	print_ip_header(pl);
	print_bytes(bs);
	pl = decapsulate_ip_header(bs);
	print_ip_header(pl);
}

void tcp_header_test(){
	struct tcp_header* pl = craft_tcp_header(1);
	char* bs = encapsulate_tcp_header(pl);
	print_tcp_header(pl);
	print_bytes(bs);
	pl = decapsulate_tcp_header(bs);
	print_tcp_header(pl);
}



void eth_header_test(){
	struct eth_header* pl = craft_eth_header(0);
	char* bs = encapsulate_eth_header(pl);
	print_eth_header(pl);
	print_bytes(bs);
	pl = decapsulate_eth_header(bs);
	print_eth_header(pl);
}

void ip_test(){
	struct ip* pl = craft_ip(1,0);
	char* bs = encapsulate_ip(pl);
	print_ip(pl);
	print_bytes(bs);
	pl = decapsulate_ip(bs,1);
	print_ip(pl);
}

void eth_test(){
	struct eth* pl = craft_eth(0,1);
	print_eth(pl,1);
	char* bs = encapsulate_eth(pl,1);
	pl = decapsulate_eth(bs,1);
	print_eth(pl,1);
}


int main(){
	get_int_input_new("hello",45);
}


