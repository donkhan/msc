#ifndef XLIB
#define XLIB

void append(char *src,char* dst,int pos,int length);
char* pluck(char *src,int pos, int length);
void print_bytes(char *s);

void print_start(char* header);
void print_end(char* header);
int get_int_input(char* field);
char get_option();
void gulp_go_ahead();
int get_int_input_new(char* field,int old_value);
char* get_string_input_new(char * field, char *old_value);
char* get_application_payload();


int get_int_input_between(char* field,int old_value,int min,int max);
char* get_string_input_with_valid_check(char * field, char *old_value,char *type);

int is_valid(const char* input,char *type);

#endif
