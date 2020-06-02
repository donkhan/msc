#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int is_valid_ip(char* ip){
	char* token = strtok(ip,".");
	int no_of_tokens = 0;
	while(token != NULL){
		no_of_tokens = no_of_tokens + 1;
		int x = atoi(token);
		if(x < 0 || x > 255){
			return 0;
		}
		token = strtok(NULL,".");
	}

	if(no_of_tokens != 4){
		return 0;
	}
	return 1;

}

int is_valid_mac(const char* mac) {
    int i = 0;
    int s = 0;
    while (*mac) {
       if (isxdigit(*mac)) {
          i++;
       }
       else if (*mac == ':' || *mac == '-') {
          if (i == 0 || i / 2 - 1 != s)
            break;
          ++s;
       }
       else {
           s = -1;
       }
       ++mac;
    }
    return (i == 12 && (s == 5 || s == 0));
}
