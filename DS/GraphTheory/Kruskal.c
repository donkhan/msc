#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DEBUG = 0;

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

void sort(struct edge *edges,int ec){
	int i,j;
	struct edge tmp;
	for(i = 0;i<ec-1;i++){
		for(j = i+1;j<ec;j++){
			if(edges[i].cost > edges[j].cost){
				tmp = edges[i];
				edges[i] = edges[j];
				edges[j] = tmp;
			}	
		}
	}
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
	int i,ec;
	char s,d;
	//printf("Adding %c%c\n",edge.src,edge.dst);
	me[count] = edge;
	count = count + 1;
	me[count].src = edge.dst;
	me[count].dst = edge.src;
	count = count + 1;
	ec = count;
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

void kruskal(struct edge *edges,int vc,int ec){
	int i,j,pos = 0,me_count = 0;
	struct edge edge;
	struct edge *sparse_matrix = (struct edge *)malloc(sizeof(struct edge) * ec);
	struct edge *multiplexed_edges = (struct edge *) malloc(sizeof(struct edge) * ec * ec -1);
	
	printf("Edges.....\n");
	print_edges(edges,ec);
	printf("Sorted....\n");
	sort(edges,ec);
	print_edges(edges,ec);
	for(i = 0;i<ec;i++){
		edge = edges[i];
		if(is_loop(edge,multiplexed_edges,me_count) == 0){
			add_to_sparse_matrix(edge,pos,sparse_matrix);
			me_count = multiplex_edges(multiplexed_edges,edge,me_count);
			pos = pos + 1;
			//print_edges(multiplexed_edges,me_count);
		}else{
			log_loop(edge);
		}
	}
	print_line();
	printf("Sparse Matrix....\n");
	print_edges(sparse_matrix,pos);
}

void test_case1(){
	//https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
	int vc = 7;
	int ec = 11;
	struct edge *edges = (struct edge *)malloc(sizeof(struct edge) * ec);
	edges[0].src = 'A'; edges[0].dst = 'B'; edges[0].cost = 7;
	edges[1].src = 'A'; edges[1].dst = 'D'; edges[1].cost = 5;


	edges[2].src = 'B'; edges[2].dst = 'C'; edges[2].cost = 8;
	edges[3].src = 'B'; edges[3].dst = 'D'; edges[3].cost = 9;
	edges[4].src = 'B'; edges[4].dst = 'E'; edges[4].cost = 7;

	edges[5].src = 'C'; edges[5].dst = 'E'; edges[5].cost = 5;

	edges[6].src = 'D'; edges[6].dst = 'E'; edges[6].cost = 15;
	edges[7].src = 'D'; edges[7].dst = 'F'; edges[7].cost = 6;

	
	edges[8].src = 'E'; edges[8].dst = 'F'; edges[8].cost = 8;
	edges[9].src = 'E'; edges[9].dst = 'G'; edges[9].cost = 9;

	edges[10].src = 'F';edges[10].dst = 'G'; edges[10].cost = 11;
	
	kruskal(edges,vc,ec);
}


int main(){
	test_case1();
	getch();
	return 1;
}









