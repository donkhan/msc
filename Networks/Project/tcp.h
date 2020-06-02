struct tcp{
	struct tcp_header* header;
	void* data;
};

struct tcp* get_sample_tcp(){
	struct tcp* payload = (struct tcp *)malloc(sizeof(struct tcp));
	payload->header = get_sample_tcp_header();
	payload->data = "SAMPLE TCP PACKET";
	return payload;
}

struct tcp* craft_tcp(int in){
	struct tcp* tcp = get_sample_tcp();
	tcp->header = craft_tcp_header(in);
	if(in){
		tcp->data = (void *)get_application_payload();
	}
	return tcp;
}



char* encapsulate_tcp(struct tcp* tcp){
	print_start("Encapsulating IP Packet");
	char* bs = encapsulate_tcp_header(tcp->header);
	char *data = tcp->data;
	int no_of_chars = strlen(data);
	for(int i = 0;i<no_of_chars;i++){
		bs = strcat(bs,int_to_binary(data[i],8));
	}
	print_bytes(bs);
	print_end("Encapsulating IP Packet");
	gulp_go_ahead();
	return bs;
}

struct tcp* decapsulate_tcp(char *c){
	struct tcp* payload = (struct tcp *)malloc(sizeof(struct tcp));
	payload->header = decapsulate_tcp_header(c);
	int e = end_of_header(payload->header);
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


void print_tcp(struct tcp* payload){
	print_tcp_header(payload->header);
	print_start("Application PayLoad ");
	printf("\nDATA: %s\n",payload->data);
	print_end("Application PayLoad ");
}
  

