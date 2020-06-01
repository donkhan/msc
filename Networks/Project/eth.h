struct eth{
	struct eth_header* header;
	struct ip_payload* data;
};

struct eth* get_sample_eth(int option){
	struct eth* eth = (struct eth *) malloc(sizeof(struct eth));
	eth->header = get_sample_eth_header();
	eth->data = (struct ip_payload *)get_sample_ip_payload(option);
	return eth;
}

struct eth* craft_eth(int in,int option){
	struct eth* eth = get_sample_eth(option);
	if(in){
		eth->header  = craft_eth_header(in);
		craft_ip_pay_load(option,in);
	}
	return eth;
}

char* encapsulate_eth(struct eth* eth,int option){
	char* header = encapsulate_eth_header(eth->header);
	struct ip_payload* ip_payload = (struct ip_payload*)eth->data;
	ip_payload->option = option;
	char* ip = encapsulate_ip_payload(ip_payload);
	char *t = calloc(strlen(ip) + strlen(header),sizeof(char));
	for(int i = 0;i<strlen(header);i++){
		t[i] = header[i];
	}
	for(int i = 0;i<strlen(header);i++){
		t[i] = header[i];
	}
	return t;
}

struct eth* decapsulate_eth(char *c,int option){
	struct eth* eth = (struct eth *)malloc(sizeof(struct eth));
	eth->header = decapsulate_eth_header(c);
	char* ip = pluck(c,96,strlen(c)-96);
	eth->data = decapsulate_ip_payload(c,option);
	return eth;
}


void print_eth(struct eth* eth,int option){
	print_eth_header(eth->header);
	struct ip_payload* ip_payload = (struct ip_payload*)eth->data;
	ip_payload->option = option;
	print_ip_payload(eth->data);
}




