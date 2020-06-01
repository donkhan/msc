struct tcp_payload{
	struct tcp_header* header;
	void* data;
};

struct tcp_payload* get_sample_tcp_payload(){
	struct tcp_payload* payload = (struct tcp_payload *)malloc(sizeof(struct tcp_payload));
	payload->header = get_sample_tcp_header();
	payload->data = "SAMPLE TCP PACKET";
	return payload;
}

struct tcp_payload* craft_tcp_payload(int in){
	struct tcp_payload* tcp_payload = get_sample_tcp_payload();
	tcp_payload->header = craft_tcp_header(in);
	if(in){
		tcp_payload->data = (void *)get_application_payload();
	}
	return tcp_payload;
}



char* encapsulate_tcp_payload(struct tcp_payload* tcp_payload){
	char* bs = encapsulate_tcp_header(tcp_payload->header);
	char *data = tcp_payload->data;
	int no_of_chars = strlen(data);
	for(int i = 0;i<no_of_chars;i++){
		bs = strcat(bs,int_to_binary(data[i],8));
	}
	return bs;
}

struct tcp_payload* decapsulate_tcp_payload(char *c){
	struct tcp_payload* payload = (struct tcp_payload *)malloc(sizeof(struct tcp_payload));
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


void print_tcp_payload(struct tcp_payload* payload){
	print_tcp_header(payload->header);
	print_start("Application PayLoad ");
	printf("\nDATA: %s\n",payload->data);
	print_end("Application PayLoad ");
}
  

