#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct ip_header {
	unsigned int version :4;
	unsigned int ihl :4;
	unsigned int dscp :6;
	unsigned int ecn :2;
	unsigned int total_length :16;
	unsigned int identification :16;
	unsigned int flags :2;
	unsigned int fragment_offset :14;

	unsigned int ttl :8;
	unsigned int protocol :8;
	unsigned int header_checksum :16;

	char src[15];
	char dst[15];
};

struct ip_header* get_sample_ip_header() {
	struct ip_header *ip_header = (struct ip_header*) malloc(
			sizeof(struct ip_header));
	ip_header->version = 4;
	ip_header->ihl = 1;
	ip_header->dscp = 2;
	ip_header->ecn = 1;
	ip_header->total_length = 300;
	ip_header->identification = 16;
	ip_header->flags = 1;
	ip_header->fragment_offset = 23;

	ip_header->ttl = 4;
	ip_header->protocol = 12;
	ip_header->header_checksum = 34;

	strcpy(ip_header->src, "192.168.1.2");
	strcpy(ip_header->dst, "192.168.1.45");

	return ip_header;
}

struct ip_header* get_empty_ip_header() {
	struct ip_header *ip_header = (struct ip_header*) malloc(
			sizeof(struct ip_header));
	return ip_header;
}

int end_of_ip_header(struct ip_header *header) {
	return 160;
}

char* encapsulate_ip_header(struct ip_header *ip_header) {
	int size = 64;

	char *ip_packet = (char*) calloc(size, sizeof(char));

	ip_packet = strcat(ip_packet, int_to_binary(ip_header->version, 4));
	ip_packet = strcat(ip_packet, int_to_binary(ip_header->ihl, 4));
	ip_packet = strcat(ip_packet, int_to_binary(ip_header->dscp, 6));
	ip_packet = strcat(ip_packet, int_to_binary(ip_header->ecn, 2));
	ip_packet = strcat(ip_packet, int_to_binary(ip_header->total_length, 16));

	ip_packet = strcat(ip_packet, int_to_binary(ip_header->identification, 16));
	ip_packet = strcat(ip_packet, int_to_binary(ip_header->flags, 2));
	ip_packet = strcat(ip_packet,
			int_to_binary(ip_header->fragment_offset, 14));

	ip_packet = strcat(ip_packet, int_to_binary(ip_header->ttl, 8));
	ip_packet = strcat(ip_packet, int_to_binary(ip_header->protocol, 8));
	ip_packet = strcat(ip_packet,
			int_to_binary(ip_header->header_checksum, 16));

	ip_packet = strcat(ip_packet, get_4_octets(ip_header->src));
	ip_packet = strcat(ip_packet, get_4_octets(ip_header->dst));

	return ip_packet;
}

struct ip_header* craft_ip_packet_header(int in) {
	struct ip_header *header = get_sample_ip_header();
	int input;
	if (in) {
		print_start("IP Header Configuration");
		header->version = get_int_input("Version");
		printf("Enter Source Address : ");
		scanf("%s", header->src);
		printf("Enter Destination Address : ");
		scanf("%s", header->dst);
		header->dscp = get_int_input("Differentiated Services Code Point");
		header->ecn = get_int_input("Explicit Congestion Notification");
		header->ttl = get_int_input("Time to Live");
		header->protocol = get_int_input("Protocol");
		print_end("IP Header Configuration");
	}
	return header;
}

struct ip_header* decapsulate_ip_header(char *c) {
	struct ip_header *ip_header = (struct ip_header*) malloc(
			sizeof(struct ip_header*));
	ip_header->version = fromBinary(pluck(c, 0, 4));
	ip_header->ihl = fromBinary(pluck(c, 4, 4));
	ip_header->dscp = fromBinary(pluck(c, 8, 6));
	ip_header->ecn = fromBinary(pluck(c, 14, 2));
	ip_header->total_length = fromBinary(pluck(c, 16, 16));

	ip_header->identification = fromBinary(pluck(c, 32, 16));
	ip_header->flags = fromBinary(pluck(c, 48, 2));
	ip_header->fragment_offset = fromBinary(pluck(c, 50, 14));

	ip_header->ttl = fromBinary(pluck(c, 64, 8));
	ip_header->protocol = fromBinary(pluck(c, 72, 8));
	ip_header->header_checksum = fromBinary(pluck(c, 80, 16));

	strcpy(ip_header->src, toIP((char*) pluck(c, 96, 32)));
	strcpy(ip_header->dst, toIP((char*) pluck(c, 128, 32)));

	return ip_header;
}

void print_ip_header(struct ip_header *ip_header) {
	print_start("IP");
	printf("\n*****************************************************");
	printf("\nVersion %d", ip_header->version);
	printf("\nInternet Header Length %d", ip_header->ihl);
	printf("\nDifferentiated Services Code Point %d", ip_header->dscp);
	printf("\nExplicit Congestion Notification %d", ip_header->ecn);
	printf("\nTotal Length %d", ip_header->total_length);
	printf("\nIdentification %d", ip_header->identification);
	printf("\nFlags %d", ip_header->flags);
	printf("\nFragment Offset %d", ip_header->fragment_offset);
	printf("\nTTL %d", ip_header->ttl);
	printf("\nProtocol %d", ip_header->protocol);
	printf("\nHeader Checksum %d", ip_header->header_checksum);

	printf("\nSource Address %s", ip_header->src);
	printf("\nDestination Address %s", ip_header->dst);
	print_end("IP");
	printf("\n");

}

