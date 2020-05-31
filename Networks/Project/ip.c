#include "lib.h"
#include "tcp_header.h"
#include "tcp.h"
#include "udp_header.h"
#include "udp.h"
#include "ip_header.h"
#include "ip.h"


void ip_test(){
	struct ip_payload* ip_payload = get_empty_ip_payload(1);
	ip_payload->header = get_empty_ip_header();
	ip_payload->header->version = 4;
	ip_payload->data = get_sample_udp_payload();
	char* bs = encapsulate_ip_payload(ip_payload,"192.168.11.12","222.21.2.212");
	printf("\n%s %lu\n",bs,strlen(bs));

	ip_payload = decapsulate_ip_payload(bs,1);
	print_ip_payload(ip_payload);
	printf("\n");
}

int main(){
	ip_test();
	return 1;
}


