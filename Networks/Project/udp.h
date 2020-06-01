struct udp{
	struct udp_header* header;
	void* data;
};

struct udp* get_sample_udp(){
	struct udp* payload = (struct udp *)malloc(sizeof(struct udp));
	payload->header = get_sample_udp_header();
	payload->data = "Sample UDP Packet";
	return payload;
}


char* encapsulate_udp(struct udp* udp){
	char* bs = encapsulate_udp_header(udp->header);
	char *data = udp->data;
	int no_of_chars = strlen(data);
	for(int i = 0;i<no_of_chars;i++){
		bs = strcat(bs,int_to_binary(data[i],8));
	}
	return bs;
}


struct udp* decapsulate_udp(char *c){
	struct udp* payload = (struct udp *)malloc(sizeof(struct udp));
	payload->header = decapsulate_udp_header(c);
	int e = end_of_udp_header(payload->header);
	int total = strlen(c);
	char* data = pluck(c,e,total-e);
	int no_of_chars = strlen(data)/8;
	char *string = malloc(no_of_chars * sizeof(char));
	for(int i = 0;i<no_of_chars;i++){
		char *p = pluck(data,i*8,8);
		string[i] = (char)fromBinary(p);
	}
	payload->data = string;
	return payload;
}


void print_udp(struct udp* payload){
	print_udp_header(payload->header);
	print_start("Application PayLoad ");
	printf("\nDATA: %s\n",payload->data);
	print_end("Application PayLoad ");
}
  
struct udp* craft_udp(int in){
	struct udp* udp = get_sample_udp();
	udp->header = craft_udp_header(in);
	if(in){
		udp->data = (void *)get_application_payload();
	}
	return udp;
}

