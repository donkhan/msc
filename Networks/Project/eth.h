struct eth{
	struct eth_header* header;
	struct ip* data;
};

struct eth* get_sample_eth(int option){
	struct eth* eth = (struct eth *) malloc(sizeof(struct eth));
	eth->header = get_sample_eth_header();
	eth->data = (struct ip *)get_sample_ip(option);
	return eth;
}

struct eth* craft_eth(int in,int option){
	struct eth* eth = get_sample_eth(option);
	if(in){
		eth->header  = craft_eth_header(in);
		struct ip* pl = craft_ip(1,0);
		eth->data = pl;
	}
	return eth;
}

char* encapsulate_eth(struct eth* eth,int option){
	print_start("Encapsulation");
	char* header = encapsulate_eth_header(eth->header);
	struct ip* ip = (struct ip*)eth->data;
	ip->option = option;
	char* bs = encapsulate_ip(ip);
	int size = strlen(header);
	size = size + strlen(bs);
	printf("\nTotal Size %d ",size);
	char *t = calloc(size,sizeof(char));
	for(int i = 0;i<strlen(header);i++){
		t[i] = header[i];
	}
	for(int i = 0;i<strlen(bs);i++){
		t[strlen(header)+i] = bs[i];
	}
	print_end("Encapsulation");
	return t;
}

struct eth* decapsulate_eth(char *c,int option){
	print_start("Decapsulation");
	print_bytes(c,strlen(c));
	struct eth* eth = (struct eth *)malloc(sizeof(struct eth));
	eth->header = decapsulate_eth_header(c);
	char* ip = pluck(c,96,strlen(c)-96);
	print_bytes(ip,strlen(ip));
	eth->data = decapsulate_ip(ip,option);
	print_end("Decapsulation");
	return eth;
}


void print_eth(struct eth* eth,int option){
	print_eth_header(eth->header);
	struct ip* ip = (struct ip*)eth->data;
	ip->option = option;
	print_ip(eth->data);
}




