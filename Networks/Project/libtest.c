#include "lib.h"

struct s{
	char x[15];
};

int main(){
	char a[15];
	strcpy(a,"192.168.1.0");
	char* addr = toIP(get_4_octets(a));
	struct s *s = malloc(sizeof(struct s *));
	printf("%s\n",s->x);
	return 1;
}
