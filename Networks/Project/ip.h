struct ip_payload{
	struct ip_header* header;
	void* data;
	int option;
};

struct ip_payload* get_sample_ip_payload(int option){
	struct ip_payload* ip_payload = (struct ip_payload *) malloc(sizeof(struct ip_payload));
	ip_payload->header = get_sample_ip_header();
	ip_payload->option = option;
	if(option == 1){
		ip_payload->data = (struct udp_payload *)get_sample_udp_payload();
	}
	if(option == 2){
		ip_payload->data = (struct tcp_payload *)get_sample_tcp_payload();
	}
	return ip_payload;
}

struct ip_payload* craft_ip_payload(int option,int in){
	struct ip_payload* ip_payload = (struct ip_payload *) malloc(sizeof(struct ip_payload));
	ip_payload->option = option;
	ip_payload->header = craft_ip_packet_header(in);
	if(option == 1){
		printf("\nCrafting UDP Payload...");
		ip_payload->data = craft_udp_payload(in);
	}else{
		printf("\nCrafting TCP Payload...");
		ip_payload->data = craft_tcp_payload(in);
	}
	return ip_payload;
}

char* encapsulate_ip_payload(struct ip_payload* ip_payload){
	char* ip = encapsulate_ip_header(ip_payload->header);
	char* x;
	if(ip_payload->option == 2){
		x = encapsulate_tcp_payload((struct tcp_payload*)ip_payload->data);
	}
	else{
		x = encapsulate_udp_payload((struct udp_payload*)ip_payload->data);
	}
	char *t = calloc(strlen(ip) + strlen(x),sizeof(char));
	for(int i = 0;i<strlen(ip);i++){
		t[i] = ip[i];
	}
	for(int i = strlen(ip);i<strlen(ip) + strlen(x);i++){
		t[i] = x[i - strlen(ip)];
	}
	return t;
}

struct ip_payload* decapsulate_ip_payload(char *c,int option){
	struct ip_payload* payload = (struct ip_payload *)malloc(sizeof(struct ip_payload));
	payload->option = option;
	payload->header = decapsulate_ip_header(c);
	int e = end_of_ip_header(payload->header);
	int total = strlen(c);
	char* data = pluck(c,e,total-e);
	if(option == 2){
		payload->data = decapsulate_tcp_payload(data);
	}
	if(option == 1){
		payload->data = decapsulate_udp_payload(data);
	}

	return payload;
}


void print_ip_payload(struct ip_payload* payload){
	print_ip_header(payload->header);
	if(payload->option == 1){
		print_udp_payload(payload->data);
	}else{
		print_tcp_payload(payload->data);
	}
}




