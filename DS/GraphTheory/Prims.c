#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DEBUG = 0;
char VERTEX_START = 'A';
char VERTEX_END = 'Z';

struct edge{
	char src;
	char dst;
	int cost;
};

void print_line();
void print_edges(struct edge *edges,int vc);
void fill(char* set,int vc);
void empty(char *set,int vc);
void add_to_set(char *set,char vertex,int vc);
void remove_from_set(char *set,char vertex,int vc);
void print_set(char *set_name,char *set,int vc);
void add_to_mst(struct edge *mst,struct edge *edge,int pos);

struct edge* find_distance(char src,char dst,struct edge* edges,int ec,int INFINITE);


void prims(struct edge *edges,int vc,int ec){
	char *reached_set = (char *)malloc(sizeof(char) * vc);
	char *unreached_set = (char *)malloc(sizeof(char) * vc);
	struct edge *mst = (struct edge *)malloc(sizeof(struct edge *)*ec);
	struct edge *t_edge;
	struct edge *x_edge;
	int no_of_edges_of_given_vertex;
	int INFINITE = 1000,pass = 0,pos = 0,i,j,d,sd;
	int srs = 0,snrs = vc;
	char next_vertex,next_possible_vertex;
	clrscr();
	fill(unreached_set,vc);
	empty(reached_set,vc);
	clrscr();

	next_vertex = VERTEX_START;
	while(snrs > 0 && pass < 10){
		printf("Pass %d \n",pass+1);
		snrs = snrs - 1;
		srs = srs + 1;
		remove_from_set(unreached_set,next_vertex,vc);
		add_to_set(reached_set,next_vertex,vc);
		print_set("U-V",unreached_set,vc);
		print_set("U  ",reached_set,vc);
		sd = INFINITE;
		next_possible_vertex = next_vertex;
		for(i = 0;i<vc;i++){
			for(j = 0;j<vc;j++){
				if(unreached_set[j] != ' ' && reached_set[i] != ' '){
					t_edge = find_distance(unreached_set[j],
						reached_set[i],edges,ec,INFINITE);
					if(t_edge->cost < sd){
						sd = t_edge->cost;
						x_edge = t_edge;
						next_possible_vertex = unreached_set[j];
					}
				}
			}
		}
		add_to_mst(mst,x_edge,pos++);
		next_vertex = next_possible_vertex;
		pass = pass + 1;
		printf("MST as of now \n");
		print_edges(mst,pos);
		getch();
		clrscr();
	}
	printf("Final MST \n");
	print_edges(mst,pos-1);
}

void print_line(){
	printf("----------------------------------------------------\n");
}

void print_edges(struct edge *edges,int ec){
	int i;
	for(i = 0;i<ec;i++){
		printf("%c to %c cost = %d \n",edges[i].src,edges[i].dst,edges[i].cost);
	}
	print_line();
}

void add_to_mst(struct edge *mst,struct edge *edge,int pos){
	struct edge e;
	e.src = edge->src;
	e.dst = edge->dst;
	e.cost = edge->cost;
	mst[pos] = e;
}

void fill(char *array,int vc){
	int i = 0;
	for(i = 0;i<vc;i++){
		array[i] = VERTEX_START + i;
	}
}

void empty(char *array,int vc){
	int i = 0;
	for(i = 0;i<vc;i++){
		array[i] = ' ';
	}
}

void add_to_set(char *set,char vertex,int vc){
	int i = 0;
	for(i = 0;i<vc;i++){
		if(set[i] == ' '){
			set[i] = vertex;
			return;
		}
	}
}

void remove_from_set(char *set,char vertex,int vc){
	int i = 0;
	for(i = 0;i<vc;i++){
		if(set[i] == vertex){
			set[i] = ' ';
			return;
		}
	}
}

void print_set(char *set_name,char *set,int vc){
	int i = 0;
	char s;
	printf("%s ",set_name);
	for(i = 0;i<vc;i++){
		char s = set[i];
		printf("%c,",s);
	}
	printf("\n");
}

struct edge* find_distance(char src,char dst,struct edge* edges,int ec,int INFINITE){
	int i = 0;
	int cost = INFINITE;
	struct edge* edge = NULL;
	edge->cost = INFINITE;

	for(i = 0;i<ec;i++){
		if(edges[i].src == src && edges[i].dst == dst){
			edge = &edges[i];
			break;
		}
		if(edges[i].src == dst && edges[i].dst == src){
			edge = &edges[i];
			break;
		}
	}
	printf("%c - %c %d %d\n",src,dst,cost,edge->cost);
	return edge;
}

void test_case1(){
	//https://www.javatpoint.com/prims-minimum-spanning-tree-algorithm
	int vc = 9;
	int ec = 10;

	struct edge *edges = (struct edge *)malloc(sizeof(struct edge) * ec);
	VERTEX_START = '0';VERTEX_END = '9';
	edges[0].src = '0'; edges[0].dst = '8'; edges[0].cost = 4;
	edges[1].src = '0'; edges[1].dst = '3'; edges[1].cost = 2;

	
	edges[2].src = '1'; edges[2].dst = '7'; edges[2].cost = 4;

	edges[3].src = '2'; edges[3].dst = '3'; edges[3].cost = 6;
	edges[4].src = '2'; edges[4].dst = '5'; edges[4].cost = 1;
	edges[5].src = '2'; edges[5].dst = '7'; edges[5].cost = 2;

	edges[6].src = '3'; edges[6].dst = '4'; edges[6].cost = 1;
	
	edges[7].src = '4'; edges[7].dst = '8'; edges[7].cost = 8;

	edges[8].src = '5'; edges[8].dst = '6'; edges[8].cost = 8;
	edges[9].src = '0'; edges[9].dst = '1'; edges[9].cost = 3;
	
	prims(edges,vc,ec);
}


void test_case2(){
	//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
        int vc = 9;
        int ec = 14;

	struct edge *edges = (struct edge *)malloc(sizeof(struct edge) * ec);
	VERTEX_START = '0';VERTEX_END = '9';
	edges[0].src = '0'; edges[0].dst = '1'; edges[0].cost = 4;
        edges[1].src = '0'; edges[1].dst = '7'; edges[1].cost = 8;

        edges[2].src = '1'; edges[2].dst = '7'; edges[2].cost = 11;
	edges[3].src = '1'; edges[3].dst = '2'; edges[3].cost = 8;

        edges[4].src = '7'; edges[4].dst = '8'; edges[4].cost = 7;
        edges[5].src = '7'; edges[5].dst = '6'; edges[5].cost = 1;

        edges[6].src = '2'; edges[6].dst = '8'; edges[6].cost = 2;
        edges[7].src = '2'; edges[7].dst = '3'; edges[7].cost = 7;
	edges[8].src = '2'; edges[8].dst = '5'; edges[8].cost = 4;

	edges[9].src = '8'; edges[9].dst = '6'; edges[9].cost = 6;
	
	edges[10].src = '5';edges[10].dst = '3'; edges[10].cost = 14;
	edges[11].src = '5';edges[11].dst = '4'; edges[11].cost = 10;


	edges[12].src = '4'; edges[12].dst = '3'; edges[12].cost = 9;
	edges[13].src = '5'; edges[13].dst = '6'; edges[13].cost = 2;

	prims(edges,vc,ec);
}

void test_case3(){
	//https://lcm.csa.iisc.ernet.in/dsa/node183.html
	int vc = 6;
	int ec = 10;

	struct edge *edges = (struct edge *)malloc(sizeof(struct edge) * ec);
	VERTEX_START = '1';VERTEX_END = '6';
	edges[0].src = '1'; edges[0].dst = '2'; edges[0].cost = 6;
	edges[1].src = '1'; edges[1].dst = '3'; edges[1].cost = 1;
	edges[2].src = '1'; edges[2].dst = '4'; edges[2].cost = 5;

	edges[3].src = '2'; edges[3].dst = '3'; edges[3].cost = 5;
	edges[4].src = '2'; edges[4].dst = '5'; edges[4].cost = 3;

	edges[5].src = '3'; edges[5].dst = '5'; edges[5].cost = 6;
	edges[6].src = '3'; edges[6].dst = '6'; edges[6].cost = 4;

	edges[7].src = '4'; edges[7].dst = '6'; edges[7].cost = 2;
	edges[8].src = '5'; edges[8].dst = '6'; edges[8].cost = 6;
	edges[8].src = '3'; edges[8].dst = '4'; edges[8].cost = 5;

	prims(edges,vc,ec);
}


int main(){
	test_case3();
	getch();
	return 1;
}








