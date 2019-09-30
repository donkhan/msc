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


void add_to_sparse_matrix(struct edge edge,int pos, struct edge *sparse_matrix){
	sparse_matrix[pos] = edge;
}



struct edge* get_edges_of_vertex(struct edge* edges,char vertex,int ec){
	int count = 0,i=0,j = 0;
	struct edge* edges_of_vertex;
	for(i = 0;i<ec;i++){
		if(edges[i].src == vertex || edges[i].dst == vertex){
			count = count + 1;
		}
	}
	edges_of_vertex = (struct edge *) malloc(sizeof(struct edge *) * count);
	for(i = 0;i<ec;i++){
		if(edges[i].src == vertex || edges[i].dst == vertex){
			edges_of_vertex[j] = edges[i];
			j = j + 1;
		}
	}
	return edges_of_vertex;
}

void sort(struct edge* edges,int ec){
	int i,j;
	struct edge t;
	for(i = 0;i<ec -1;i++){
		for(j = i+1;j<ec;j++){
			if(edges[i].cost > edges[j].cost){
				t = edges[i];
				edges[i] = edges[j];
				edges[j] = t;		
			}
		}
	}
}

int get_no_of_edges(struct edge* edges){
	int i = 0;
	while(1){
		if(edges[i].src >= VERTEX_START && edges[i].src <=  VERTEX_END){
			i = i + 1;
		}else{
			break;
		}
	}
	return i;
	
}


int get_array_value(char vertex){
	return vertex - VERTEX_START;
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

int is_not_empty(char *set,int vc){
	int i = 0;
	for(i = 0;i<vc;i++){
		if(set[i] != ' '){
			return 1;
		}
	}
	return 0;
}

char get_next_vertex(char *array,int vc){
	int i = 0;
	for(i = 0;i<vc;i++){
		if(array[i] != ' '){
			return array[i];
		}
	}
	return ' ';
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

void print_set(char *set,int vc){
	int i = 0;
	char s;
	for(i = 0;i<vc;i++){
		char s = set[i];
		if(s == ' '){
			s = '@';
		}
		printf("%c\t",s);
	}
	printf("\n");
}

void prims(struct edge *edges,int vc,int ec){
	char *reached_set = (char *)malloc(sizeof(char) * vc);
	char *unreached_set = (char *)malloc(sizeof(char) * vc);
	struct edge *sparse_matrix = (struct edge *)malloc(sizeof(struct edge *)*ec);
	struct edge *edges_of_vertex;
	struct edge candidate_edge;
	int no_of_edges_of_given_vertex;
	int pass = 0,pos = 0,i = 0;
	int size_of_unreached = vc,size_of_reached = 0,size_to_calculate;
	char next_vertex;
	clrscr();
	fill(unreached_set,vc);
	empty(reached_set,vc);
	print_edges(edges,ec);
	getch();

	while(pass < 2){
		next_vertex = VERTEX_START;
		remove_from_set(unreached_set,next_vertex,vc);
		add_to_set(reached_set,next_vertex,vc);
		print_set(unreached_set,vc);
		print_set(reached_set,vc);
		size_of_reached = size_of_reached + 1;
		size_of_unreached = size_of_unreached - 1;
		size_to_calculate = size_of_reached + size_of_unreached;
		edges_of_vertex = (struct edge *)malloc(sizeof(struct edge *) * size_to_calculate);




		pass = pass + 1;
	}


	printf("Final Sparse Matrix \n");
	print_edges(sparse_matrix,pos);
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

int main(){
	test_case1();
	getch();
	return 1;
}








