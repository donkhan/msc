#include<stdlib.h>
#include<stdio.h>


struct edge{
	char s;
	char d;
};

void print(char *q,int front,int rear){
	int i;
	printf("\n Queue...");
	for(i = rear;i>=front;i--){
		printf("%c ",q[i]);
	}
	printf("\n--------------------------\n");
}

void push(char *q,char c,int* pos){
	q[*pos] = c;
	*pos = *pos + 1;
}

char pop(char *q,int *pos){
	char c = q[*pos];
	*pos = *pos  + 1;
	return c;
}

int is_empty(char *q,int front,int rear){
	return front == rear;
}

int is_present(char *q,char c,int front,int rear){
	int i = 0;
	for(i = front;i<=rear;i++){
		if(q[i] == c){
			return 1;
		}
	}
	return 0;
}

	
int main(){
	int n;
	char *q;
	int front = 0;
	int rear = 0;
	char c;
	int i;

	struct edge *edges; 
	char fc = 'S';
	
	int ec = 9;
	edges = malloc(sizeof(struct edge *) * ec);
	edges[0].s = 'S'; edges[0].d = 'A';
	edges[1].s = 'S'; edges[1].d = 'C';
	edges[2].s = 'A'; edges[2].d = 'B';
	edges[3].s = 'A'; edges[3].d = 'D';
	edges[4].s = 'B'; edges[4].d = 'E';
	edges[5].s = 'S'; edges[5].d = 'F';
	edges[6].s = 'C'; edges[6].d = 'A';
	edges[7].s = 'C'; edges[7].d = 'D';
	edges[8].s = 'D'; edges[8].d = 'E';
	edges[9].s = 'F'; edges[9].d = 'E';

	q = malloc(sizeof(char *) * n);
	
        push(q,fc,&rear);
	
	while(is_empty(q,front,rear) != 1){
		char c = pop(q,&front);
		printf("%c \n",c);
		for(i = 0;i<ec;i++){
			if(edges[i].s == c){
				if(is_present(q,edges[i].d,0,rear) == 0){
					push(q,edges[i].d,&rear);
				}
			}
		}		
	}
	return 1;
	
}




