#include<stdio.h>
#include<stdlib.h>

int DEBUG = 1;
char VERTEX_NAMING_STARTS_WITH = 'a';

struct edge{
	char source;
	char destination;
	int  cost;
};

void print_line(){
	printf("-------------------------------------------------------------------------------------\n");
}

void print_edges(struct edge *edges,int no){
	int i;
	print_line();
	printf("Edges ......\n");
	for(i = 0;i<no;i++){
		printf("Source = %c Destination = %c  Cost = %d\n",edges[i].source,edges[i].destination,edges[i].cost);
	}
	print_line();
}

void fillInfinites(int *cm,int vertex_count,int INFINITE){
	int i,j;
	for(i = 0;i<vertex_count;i++){
		for(j = 0;j<vertex_count;j++){
			cm[i] = INFINITE;
		}
	}	
}

void print_costmatrix(int* cm,int vertex_count,int row,int INFINITE){
	int i,j;
	for(i = 0;i<vertex_count;i++){
		if(cm[i] != INFINITE){
			printf("%d \t",cm[i]);
		}else{
			printf("INF\t");
		}
	}
	printf("\n");
	
}


char getChar(int pos){
	return VERTEX_NAMING_STARTS_WITH + pos;
}


int get_distance(char s,char e,struct edge *edges,int edges_count,int INFINITE){
	int i;
	if(s == e){
		return 0;
	}
	for(i = 0;i<edges_count;i++){
		struct edge edge = edges[i];
		if(edge.source == s && edge.destination == e){
			return edge.cost;
		}
		if(edge.source == e && edge.destination == s){
			return edge.cost;
		} 
	}

	return INFINITE;
}


void find_neighbours_and_update_short_distance(int row,int *lm,struct edge *edges,char source_vertex,int cost,int vertex_count,int edges_count,int INFINITE){
	int j,distance,total_distance,k;
	char via = getChar(row);
	for(j = 0;j<vertex_count;j++){
		char dest_vertex = getChar(j);
		distance = get_distance(via,dest_vertex,edges,edges_count,INFINITE);
		total_distance = distance + cost;
		if(DEBUG)
			printf("%c to %c via %c ld %d Total Distance %d \n",source_vertex,dest_vertex,via,distance,total_distance);
		if (lm[j] > total_distance){
			lm[j] = total_distance;
			
		}
	}
}

int is_visited(char c,char* visited_vertices,int vertex_count){
	int i;
	for(i = 0;i<vertex_count;i++){
		if(visited_vertices[i] == c){
			return 1;
		}
	}
	return 0;
}

char get_next_vertex(int row,char* visited_vertices,int *cm,int vertex_count,int INFINITE){
	int i,col;
	char next_vertex = '@';
	int val = INFINITE;
	for(col = 0;col<vertex_count;col++){
		char c = getChar(col);
		if(is_visited(c,visited_vertices,vertex_count) == 1){
			continue;
		}
		if(cm[row] < val){
			val = cm[row];
			next_vertex = c;
		}

	}
	return next_vertex;
}

int get_position(char vertex){
	return vertex - VERTEX_NAMING_STARTS_WITH;
}

void add_to_visited_vertices(char vertex,int pos,char* visited_vertices){
	visited_vertices[pos] = vertex;
}

void print_final_output(int* cost_matrix,int vertex_count,char source_vertex,int INFINITE){
	int i,j,cost = 0;
	printf("Shortest Distance between %c and other nodes \n",source_vertex);
	for(i = 0;i<vertex_count;i++){
		printf("To %c  = %d \t",getChar(i),cost_matrix[i]);
		if (cost < cost_matrix[i] && cost_matrix[i] != INFINITE){
			cost = cost_matrix[i];
		}
	}
	printf("\nCost of the Matrix %d \n",cost);
	
}

void dijikstra(struct edge *edges,int vertex_count,int edges_count){
	char source_vertex = VERTEX_NAMING_STARTS_WITH,next_vertex = source_vertex;
	int i,j,row,cost,pos,INFINITE = 1000;	
	char* visited_vertices = (char *) malloc(sizeof(char) * vertex_count);
	int* cost_matrix = (int *)malloc(sizeof(int) * vertex_count);
	for(i = 0;i<vertex_count;i++){
		visited_vertices[i] = ' ';
	}

	print_line();
	print_edges(edges,edges_count);
	fillInfinites(cost_matrix,vertex_count,INFINITE);

	row = 0;cost = 0;
	for(i = 0;i<vertex_count;i++){
		print_line();
		printf("Vertex %c with cost of %d \n",next_vertex,cost);
		find_neighbours_and_update_short_distance(row,cost_matrix,edges,source_vertex,cost,vertex_count,edges_count,INFINITE);
		add_to_visited_vertices(next_vertex,i,visited_vertices);
		print_costmatrix(cost_matrix,vertex_count,row,INFINITE);
		next_vertex = get_next_vertex(row,visited_vertices,cost_matrix,vertex_count,INFINITE);
		if (next_vertex == '@'){
			break;
		}
		pos = get_position(next_vertex);
		cost = cost_matrix[pos];
		row = pos;
		print_line();
	}
	print_final_output(cost_matrix,vertex_count,source_vertex,INFINITE);
}

void test_case1(){
	int edges_count = 7;
	int vertex_count = 5;
	int s = sizeof(struct edge *);
	struct edge *edges = (struct edge *)malloc(s * edges_count);
	edges[0].source = 'a';edges[0].destination = 'b'; edges[0].cost = 7;
        edges[1].source = 'a';edges[1].destination = 'c'; edges[1].cost = 3;
        edges[2].source = 'b';edges[2].destination = 'c'; edges[2].cost = 1;
        edges[3].source = 'b';edges[3].destination = 'd'; edges[3].cost = 2;
        edges[4].source = 'b';edges[4].destination = 'e'; edges[4].cost = 6;
	edges[5].source = 'c';edges[5].destination = 'd'; edges[5].cost = 2;
	edges[6].source = 'd';edges[6].destination = 'e'; edges[6].cost = 4;	
	dijikstra(edges,vertex_count,edges_count);
}


void test_case2(){
	int edges_count = 4;
	int vertex_count = 4;
	int s = sizeof(struct edge *);
	struct edge *edges = (struct edge *)malloc(s * edges_count);
	edges[0].source = 'a';edges[0].destination = 'b'; edges[0].cost = 5;
        edges[1].source = 'a';edges[1].destination = 'c'; edges[1].cost = 15;
	edges[2].source = 'b';edges[2].destination = 'c'; edges[2].cost = 6;
        edges[3].source = 'c';edges[3].destination = 'd'; edges[3].cost = 2;
	dijikstra(edges,vertex_count,edges_count);
}

void test_case3(){
	int edges_count = 4;
	int vertex_count = 4;
	int s = sizeof(struct edge *);
	struct edge *edges = (struct edge *) malloc(s * edges_count);
	edges[0].source = 'a';edges[0].destination = 'b'; edges[0].cost = 24;
	edges[1].source = 'a';edges[1].destination = 'c'; edges[1].cost = 3;
        edges[2].source = 'a';edges[2].destination = 'd'; edges[2].cost = 20;
	edges[3].source = 'c';edges[3].destination = 'd'; edges[3].cost = 12;
	dijikstra(edges,vertex_count,edges_count);
}

void test_case4(){
	int i;
	int edges_count = 0;
	int vertex_count = 0;
	struct edge *edges;
	printf("Enter Edge Count ");
	scanf("%d",&edges_count);
	printf("Enter Vertex Count ");
	scanf("%d",&vertex_count);
	edges = (struct edge *)malloc(sizeof(struct edge) * edges_count);
	for(i = 0;i<edges_count;i++){
		printf("Enter Source Edge ");
		scanf(" %c",&edges[i].source);
		printf("Enter Destination Edge ");
		scanf(" %c",&edges[i].destination);
		printf("Enter Distance ");
		scanf("%d",&edges[i].cost);
	}
	dijikstra(edges,vertex_count,edges_count);
	
}

void test_case5(){
	int edges_count = 4;
	int vertex_count = 4;
	int s = sizeof(struct edge *);
	struct edge *edges = (struct edge *) malloc(s * edges_count);

	VERTEX_NAMING_STARTS_WITH = 'A';
	edges[0].source = 'A';edges[0].destination = 'B'; edges[0].cost = 24;
        edges[1].source = 'B';edges[1].destination = 'C'; edges[1].cost = 3;
        edges[2].source = 'C';edges[2].destination = 'D'; edges[2].cost = 20;
        edges[3].source = 'D';edges[3].destination = 'D'; edges[3].cost = 12;
	dijikstra(edges,vertex_count,edges_count);
}


void test_case6(){
	//https://www.youtube.com/watch?v=k0jStC6nopU
        int edges_count = 7;
        int vertex_count = 5;
        struct edge* edges = (struct edge *)malloc(sizeof(struct edge) * edges_count);
        VERTEX_NAMING_STARTS_WITH = 'A';
        edges[0].source = 'A';edges[0].destination = 'B'; edges[0].cost = 8;
        edges[1].source = 'A';edges[1].destination = 'C'; edges[1].cost = 12;
        edges[2].source = 'B';edges[2].destination = 'C'; edges[2].cost = 2;
        edges[3].source = 'B';edges[3].destination = 'D'; edges[3].cost = 5;
	edges[4].source = 'B';edges[4].destination = 'E'; edges[4].cost = 9;
	edges[5].source = 'C';edges[5].destination = 'D'; edges[5].cost = 1;
	edges[6].source = 'D';edges[6].destination = 'E'; edges[6].cost = 3;
        dijikstra(edges,vertex_count,edges_count);
}

void test_case7(){
        //https://www.youtube.com/watch?v=eFZCPlZCyIM
	int edges_count = 14;
        int vertex_count = 8;
        struct edge* edges = (struct edge *)malloc(sizeof(struct edge) * edges_count);
        VERTEX_NAMING_STARTS_WITH = 'A';
        edges[0].source = 'A';edges[0].destination = 'B'; edges[0].cost = 3;
        edges[1].source = 'A';edges[1].destination = 'C'; edges[1].cost = 4;
	edges[2].source = 'A';edges[2].destination = 'D'; edges[2].cost = 7;
	
        edges[3].source = 'B';edges[3].destination = 'C'; edges[3].cost = 1;
        edges[4].source = 'B';edges[4].destination = 'F'; edges[4].cost = 5;

        edges[5].source = 'C';edges[5].destination = 'D'; edges[5].cost = 2;
        edges[6].source = 'C';edges[6].destination = 'F'; edges[6].cost = 6;

	edges[7].source = 'D';edges[7].destination = 'E'; edges[7].cost = 3;
	edges[8].source = 'D';edges[8].destination = 'G'; edges[8].cost = 6;

	edges[9].source = 'E';edges[9].destination = 'F'; edges[9].cost = 1;
	edges[10].source = 'E'; edges[10].destination = 'G'; edges[10].cost = 3;
	edges[11].source = 'E'; edges[11].destination = 'H'; edges[11].cost = 4;

	edges[12].source = 'F';edges[12].destination = 'H'; edges[12].cost = 8;
	edges[13].source = 'G';edges[13].destination = 'H'; edges[13].cost = 2;


	dijikstra(edges,vertex_count,edges_count);
}

int main(){
	test_case7();
	//getch();
}
