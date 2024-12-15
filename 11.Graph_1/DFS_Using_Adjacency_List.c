#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode{
	int vertex;		// 연결된 정점 번호
	struct GraphNode* link;		// 다음 노드
} GraphNode;

typedef struct GraphType{
	int n;	
	GraphNode* adj_list[MAX_VERTICES];		// 인접 리스트 배열
} GraphType;
int visited[MAX_VERTICES];

void init(GraphType* g){
	g->n = 0;
	for(int v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v){
	if(((g->n) + 1) > MAX_VERTICES){
		fprintf(stderr, "그래프: 정점의 개수 초과\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end){
	if(start >= g->n || end >= g->n){
		fprintf(stderr, "그래프: 정점 번호 오류\n");
		return;
	}
	
	// start -> end 간선 추가
	GraphNode* node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = end;
	node->link = g->adj_list[start];
	g->adj_list[start] = node;

	// end -> start 간선 추가 (무방향 그래프)
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = start;
	node->link = g->adj_list[end];
	g->adj_list[end] = node;
}

// 인접 리스트로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_list(GraphType* g, int v){
	GraphNode* w;
	visited[v] = TRUE;		// 정점 v의 방문 표시
	printf("정점 %d -> ", v);		// 방문한 정점 출력

	for(w = g->adj_list[v]; w; w = w->link)		// 인접 정점 탐색
		if(!visited[w->vertex])
			dfs_list(g, w->vertex);		// 정점 w에서 DFS 새로 시작
}

int main(){
	GraphType* g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);

	for(int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	printf("깊이 우선 탐색\n");
	dfs_list(g, 0);
	printf("\n");

	free(g);

	return 0;
}