//BellmanFord (방향 가중 그래프)
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vertex vertex;
typedef struct edge edge;
typedef struct Digraph Digraph;
typedef struct Node Node;

void buildGraph();
void insertVertex(int i);
void insertDirectedEdge(int uName, int wName, int i, int weight);
int index(int vName);
void addFirst(Node* H, int i);

struct Node {
	int element;
	Node* next;
};

struct Digraph {
	vertex* vertices;
	edge* edges;
};


struct vertex {
	int name;
	Node* outEdges;
	Node* inEdges;
	int distance;
	int inDegree;
};

struct edge {
	int origin;
	int weight;
	int destination;
};

int n, m, s;
Digraph G;

void buildGraph()
{
	vertex* v;
	int i, weight;
	int uName, wName;
	scanf("%d %d %d", &n, &m, &s);

	G.vertices = (vertex*)malloc(sizeof(vertex) * n);
	G.edges = (edge*)malloc(sizeof(edge) * m);

	for (i = 0;i < n;i++)
		insertVertex(i);

	for (i = 0;i < m;i++) {
		scanf("%d %d %d", &uName, &wName, &weight);
		insertDirectedEdge(uName, wName, i, weight);
	}

}

void insertVertex(int i)
{
	G.vertices[i].name = i + 1;
	G.vertices[i].outEdges = (Node*)malloc(sizeof(Node) * n);
	G.vertices[i].outEdges->next = NULL;
	G.vertices[i].inEdges = (Node*)malloc(sizeof(Node) * n);
	G.vertices[i].inEdges->next = NULL;
	G.vertices[i].inDegree = 0;
}

void insertDirectedEdge(int uName, int wName, int i, int weight)
{
	int u, w;
	u = index(uName);
	w = index(wName);

	G.edges[i].origin = u;
	G.edges[i].destination = w;
	G.edges[i].weight = weight;

	addFirst(G.vertices[u].outEdges, i);
	addFirst(G.vertices[w].inEdges, i);
	G.vertices[w].inDegree++;

}

int index(int vName)
{
	int i;
	for (i = 0;i < n;i++)
	{
		if (G.vertices[i].name == vName)
			return i;
	}
}

void addFirst(Node* H, int i)
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->element = i;
	node->next = H->next;
	H->next = node;

	return;
}

void BellmanFordShortestPaths() {
	int u, z;
	int i, j;
	for (i = 0;i < n;i++) {
		G.vertices[i].distance = 100000;
	}

	G.vertices[s - 1].distance = 0;

	for (i = 1;i < n - 1;i++)
		for (j = 0;j < m;j++) {
			u = G.edges[j].origin;
			z = G.edges[j].destination;
			if (G.vertices[z].distance > G.vertices[u].distance + G.edges[j].weight && G.vertices[u].distance != 100000) {
				G.vertices[z].distance = G.vertices[u].distance + G.edges[j].weight;
			}
		}

	for (i = 0;i < n;i++) {
		if (G.vertices[i].distance != 100000 && G.vertices[i].name != s)
			printf("%d %d\n", G.vertices[i].name, G.vertices[i].distance);
	}
}

int main()
{
	buildGraph();
	BellmanFordShortestPaths();

	return 0;
}
*/