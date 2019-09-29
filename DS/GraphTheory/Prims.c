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

int is_loop(struct edge e,struct edge *me,int count){
	int i;
	
	for(i = 0;i<count;i++){
		if(me[i].src == e.dst && me[i].dst == e.src){
			return 1;
		}
	}
	return 0;
}

void log_loop(struct edge e){
	printf("Edge %c to %c will generate a loop. so ignored. \n",e.src,e.dst);
}

void add_to_sparse_matrix(struct edge edge,int pos, struct edge *sparse_matrix){
	sparse_matrix[pos] = edge;
}


int multiplex_edges(struct edge *me,struct edge edge,int count){
	int i;
	char s,d;
	//printf("Adding %c%c\n",edge.src,edge.dst);
	me[count] = edge;
	count = count + 1;
	me[count].src = edge.dst;
	me[count].dst = edge.src;
	count = count + 1;
	int ec = count;
	for(i = 0;i<ec;i++){
		if(me[i].dst == edge.src){
			s = me[i].src;
			d = edge.dst;
			me[count].src= s;
			me[count].dst = d;
			count = count + 1;
			me[count].src = d;
			me[count].dst = s;
			count = count + 1;	
		}
		if(me[i].src == edge.dst){
                        s = me[i].dst;
                        d = edge.src;
                        me[count].src= s;
                        me[count].dst = d;
                        count = count + 1;
                        me[count].src = d;
                        me[count].dst = s;
                        count = count + 1;
                }
	}	
	
	return count;	
}

struct edge* get_edges_of_vertex(struct edge* edges,char vertex,int ec){
	int count = 0,i=0,j = 0;
	struct edge* edges_of_vertex;
	for(i = 0;i<ec;i++){
		if(edges[i].src == vertex){
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

int get_no_edges(struct edge* edges){
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

void prims(struct edge *edges,int vc,int ec){
	int i,j,pos = 0,me_count = 0;
	struct edge edge;
	struct edge *sparse_matrix = (struct edge *)malloc(sizeof(struct edge) * ec);
	struct edge *multiplexed_edges = (struct edge *) malloc(sizeof(struct edge) * ec * ec -1);
	char* visited_vertices;
	int* cm;
	char next_vertex = VERTEX_START;
	int vsc = 0;
	int pass = 0;
	int no_of_edges = 0;	
	int INFINITE = 10000;
	int v;
	struct edge e;

	cm = (int *)malloc(sizeof(int) * vc);
	visited_vertices = (char *)malloc(sizeof(char) * vc);
	for(i = 0;i<vc;i++){
		visited_vertices[i] = ' ';
		cm[i] = INFINITE;
	}	

	printf("Edges.....\n");
	print_edges(edges,ec);
	
	while(pass <= vc){
		printf("Operating on Vertex %c\n",next_vertex);
		struct edge *edges_of_vertex = get_edges_of_vertex(edges,next_vertex,ec);
		no_of_edges = get_no_edges(edges_of_vertex);
		sort(edges_of_vertex,no_of_edges);
		print_edges(edges_of_vertex,no_of_edges);
		
		for(i = 0;i<no_of_edges;i++){
			e = edges_of_vertex[i];
			if(is_loop(e,multiplexed_edges,me_count) == 0){
				add_to_sparse_matrix(e,pos,sparse_matrix);
				pos = pos + 1;
				me_count = multiplex_edges(multiplexed_edges,e,me_count);
				next_vertex = e.dst;
				break;
			}else{
				log_loop(e);
			}		
		}
				
	
		pass = pass + 1;
	}
	print_line();
	printf("Sparse Matrix....\n");
	print_edges(sparse_matrix,pos);
}

void test_case1(){
	//https://www.javatpoint.com/prims-minimum-spanning-tree-algorithm
	int vc = 7;
	int ec = 9;
	VERTEX_START = '0';VERTEX_END = '9';
	struct edge *edges = (struct edge *)malloc(sizeof(struct edge) * ec);
	edges[0].src = '0'; edges[0].dst = '5'; edges[0].cost = 10;
	edges[1].src = '0'; edges[1].dst = '1'; edges[1].cost = 28;

	edges[2].src = '5'; edges[2].dst = '4'; edges[2].cost = 25;

	edges[3].src = '4'; edges[3].dst = '3'; edges[3].cost = 22;
	edges[4].src = '4'; edges[4].dst = '6'; edges[4].cost = 24;

	edges[5].src = '6'; edges[5].dst = '1'; edges[5].cost = 14;
	edges[6].src = '6'; edges[6].dst = '3'; edges[6].cost = 18;

	edges[7].src = '3'; edges[7].dst = '2'; edges[7].cost = 12;
	edges[8].src = '2'; edges[8].dst = '1'; edges[8].cost = 16;
	
	prims(edges,vc,ec);
}


void test_case2(){
        //https://www.javatpoint.com/prims-minimum-spanning-tree-algorithm
        int vc = 9;
        int ec = 14;
        VERTEX_START = '0';VERTEX_END = '9';
        struct edge *edges = (struct edge *)malloc(sizeof(struct edge) * ec);
        edges[0].src = '0'; edges[0].dst = '1'; edges[0].cost = 4;
        edges[1].src = '0'; edges[1].dst = '7'; edges[1].cost = 8;

        edges[2].src = '1'; edges[2].dst = '7'; edges[2].cost = 11;
        edges[3].src = '1'; edges[3].dst = '2'; edges[3].cost = 8;

        edges[4].src = '7'; edges[4].dst = '8'; edges[4].cost = 7;
        edges[5].src = '7'; edges[5].dst = '6'; edges[5].cost = 1;

        edges[6].src = '2'; edges[6].dst = '8'; edges[6].cost = 2;
        edges[7].src = '2'; edges[7].dst = '3'; edges[7].cost = 7;
        edges[8].src = '2'; edges[8].dst = '4'; edges[8].cost = 5;

	edges[9].src = '8'; edges[9].dst = '6'; edges[9].cost = 6;
	
	edges[10].src = '5';edges[10].dst = '3'; edges[10].cost = 14;
	edges[11].src = '5';edges[11].dst = '4'; edges[11].cost = 10;


	edges[12].src = '4'; edges[12].dst = '3'; edges[12].cost = 9;
	edges[12].src = '5'; edges[12].dst = '6'; edges[12].cost = 2;

        prims(edges,vc,ec);
}

int main(){
	test_case2();
	return 1;
}









