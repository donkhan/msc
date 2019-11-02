#include<stdlib.h>
#include<stdio.h>


struct edge{
	char s;
	char d;
};


int is_visited(char *set,char c,int n){
	int i = 0;
//	printf("Check presence of %c in set \n",c);
	for(i = 0;i<n;i++){
		if(set[i] == c){
			return 1;
		}
	}
	return 0;
}


void dfs(char c,struct edge *edges,int ec,int n,char *visited,int *pos){
	int i = 0;
//	printf("DFS\n");
	if(is_visited(visited,c,n) == 1){
		return;
	}
	printf("%c \n",c);
	visited[*pos] = c;
	*pos = *pos + 1;
	for(i = 0;i<ec;i++){
		if(edges[i].s == c){
			dfs(edges[i].d,edges,ec,n,visited,pos);
		}
	}

}


	
int main(){
	int n = 7;
	char *visited;
	char c;
	int i;
	struct edge *edges; 
	char fc = 'S';
	int x = 0;

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

	visited = malloc(sizeof(char *) * n);
	for(i = 0;i<n;i++){
		visited[i] = '@';
	}
	
	dfs(fc,edges,ec,n,visited,&x);
	return 1;
	
}




