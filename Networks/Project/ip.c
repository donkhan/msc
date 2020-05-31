#include "ip.h"


void ip_test(){
	struct ip_payload* ip_payload = get_sample_ip_payload();
	//print_ip_payload(ip_payload);

	char* bs = encapsulate_ip_payload(ip_payload);
	printf("\n%s %lu\n",bs,strlen(bs));

	ip_payload = decapsulate_ip_payload(bs);
	print_ip_payload(ip_payload);
}

int main(){
	ip_test();
	return 1;
}


