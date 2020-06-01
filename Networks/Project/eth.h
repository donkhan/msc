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
		struct ip_payload* pl = craft_ip_payload(1,1);
		eth->data = pl;
	}
	return eth;
}

char* encapsulate_eth(struct eth* eth,int option){
	print_start("Encapsulation");
	char* header = encapsulate_eth_header(eth->header);
	struct ip_payload* ip_payload = (struct ip_payload*)eth->data;
	ip_payload->option = option;
	char* ip = encapsulate_ip_payload(ip_payload);
	int size = strlen(header);
	size = size + strlen(ip);
	printf("\nTotal Size %d ",size);
	char *t = calloc(size,sizeof(char));
	for(int i = 0;i<strlen(header);i++){
		t[i] = header[i];
	}
	for(int i = 0;i<strlen(ip);i++){
		t[strlen(header)+i] = ip[i];
	}print_end("Encapsulation");
	return t;
}

struct eth* decapsulate_eth(char *c,int option){
	print_start("Decapsulation");
	print_bytes(c,strlen(c));
	struct eth* eth = (struct eth *)malloc(sizeof(struct eth));
	eth->header = decapsulate_eth_header(c);
	char* ip = pluck(c,96,strlen(c)-96);
	print_bytes(ip,strlen(ip));
	eth->data = decapsulate_ip_payload(ip,option);
	print_end("Decapsulation");
	return eth;
}


void print_eth(struct eth* eth,int option){
	print_eth_header(eth->header);
	struct ip_payload* ip_payload = (struct ip_payload*)eth->data;
	ip_payload->option = option;
	print_ip_payload(eth->data);
}




