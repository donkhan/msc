struct ip{
	struct ip_header* header;
	void* data;
	int option;
};

struct ip* get_sample_ip(int option){
	struct ip* ip = (struct ip *) malloc(sizeof(struct ip));
	ip->header = get_sample_ip_header();
	ip->option = option;
	if(option == 1){
		ip->data = (struct udp *)get_sample_udp();
	}
	if(option == 2){
		ip->data = (struct tcp *)get_sample_tcp();
	}
	return ip;
}

struct ip* craft_ip(int option,int in){
	printf("\nOption %d\n",option);
	struct ip* ip = (struct ip *) malloc(sizeof(struct ip));
	ip->option = option;
	ip->header = craft_ip_packet_header(in);
	if(option == 1){
		ip->data = craft_udp(in);
	}else{
		ip->data = craft_tcp(in);
	}
	return ip;
}

char* encapsulate_ip(struct ip* ip){
	print_start("Encapsulating IP Packet");
	char* bs = encapsulate_ip_header(ip->header);
	char* x;
	if(ip->option == 2){
		x = encapsulate_tcp((struct tcp*)ip->data);
	}
	else{
		x = encapsulate_udp((struct udp*)ip->data);
	}
	char *t = calloc(strlen(bs) + strlen(x),sizeof(char));
	for(int i = 0;i<strlen(bs);i++){
		t[i] = bs[i];
	}
	for(int i = strlen(bs);i<strlen(bs) + strlen(x);i++){
		t[i] = x[i - strlen(bs)];
	}
	print_bytes(t);
	print_end("Encapsulating IP Packet");
	gulp_go_ahead();
	return t;
}

struct ip* decapsulate_ip(char *c,int option){
	struct ip* payload = (struct ip *)malloc(sizeof(struct ip));
	payload->option = option;
	payload->header = decapsulate_ip_header(c);
	int e = end_of_ip_header(payload->header);
	int total = strlen(c);
	char* data = pluck(c,e,total-e);
	if(option == 2){
		payload->data = decapsulate_tcp(data);
	}
	if(option == 1){
		payload->data = decapsulate_udp(data);
	}

	return payload;
}


void print_ip(struct ip* payload){
	print_ip_header(payload->header);
	if(payload->option == 1){
		print_udp(payload->data);
	}else{
		print_tcp(payload->data);
	}
}




