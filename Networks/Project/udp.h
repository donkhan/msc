struct udp_payload{
	struct udp_header* header;
	void* data;
};

struct udp_payload* get_sample_udp_payload(){
	struct udp_payload* payload = (struct udp_payload *)malloc(sizeof(struct udp_payload));
	payload->header = get_sample_udp_header();
	payload->data = "U";
	return payload;
}


char* encapsulate_udp_payload(struct udp_payload* udp_payload){
	char* bs = encapsulate_udp_header(udp_payload->header);
	char *data = udp_payload->data;
	int no_of_chars = strlen(data);
	for(int i = 0;i<no_of_chars;i++){
		bs = strcat(bs,int_to_binary(data[i],8));
	}
	return bs;
}


struct udp_payload* decapsulate_udp_payload(char *c){
	struct udp_payload* payload = (struct udp_payload *)malloc(sizeof(struct udp_payload));
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


void print_udp_payload(struct udp_payload* payload){
	print_udp_header(payload->header);
	print_start("Application PayLoad ");
	printf("\nDATA: %s\n",payload->data);
	print_end("Application PayLoad ");
}
  
struct udp_payload* craft_udp_payload(int in){
	struct udp_payload* udp_payload = get_sample_udp_payload();
	udp_payload->header = craft_udp_header(in);
	return udp_payload;
}

