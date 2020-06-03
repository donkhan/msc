#ifndef CONVERT
#define CONVERT
char* int_to_binary(int value,int length);
char* int_star_to_binary(unsigned int* ptr,int no_of_bytes);
int fromBinary(const char *s);
char* toHEX(char *string);

char* get_6_octets(char* mac);
char* get_hex_char(char *x);
char* toHEX(char *string);
char* get_4_octets(char* a);
char* toIP(char* a);


#endif
