#include "lib.h"

struct s{
	char x[15];
};

int main(){
	char a[15];
	strcpy(a,"192.168.1.0");
	printf("%s\n",a);
	char* addr = toIP(get_4_octets(a));
	printf("Final %s\n",addr);

	struct s *s = malloc(sizeof(struct s *));
	strcpy(s->x,"192.168.1.2");
	printf("%s\n",s->x);
	return 1;
}
