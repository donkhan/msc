#include "lib.h"
#include "tcp.h"


void tcp_test(){
	struct tcp_payload* tcp_payload = craft_tcp_payload(0);
	char* bs = encapsulate_tcp_payload(tcp_payload);
	print_tcp_payload(tcp_payload);
	print_bytes(bs,strlen(bs));
	tcp_payload = decapsulate_tcp_payload(bs);
	print_tcp_payload(tcp_payload);
}

int main(){
	tcp_test();
}


