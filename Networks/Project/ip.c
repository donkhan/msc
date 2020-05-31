#include "lib.h"
#include "tcp_header.h"
#include "tcp.h"
#include "udp_header.h"
#include "udp.h"
#include "ip_header.h"
#include "ip.h"


void ip_test(){
	struct ip_payload* ip_payload = get_sample_ip_payload(1);
	printf("Got Sample Payload");
	ip_payload->data = get_sample_udp_payload();

	char* bs = encapsulate_ip_payload(ip_payload);
	printf("\n%s %lu\n",bs,strlen(bs));

	ip_payload = decapsulate_ip_payload(bs,1);
	print_ip_payload(ip_payload);
}

int main(){
	ip_test();
	return 1;
}


