#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Q_vertex Q_vertex;
typedef struct vertex vertex;
typedef struct edge edge;
typedef struct Digraph Digraph;
typedef struct Node Node;

void buildGraph();
void insertVertex(char vName, int i, int pw);
void insertDirectedEdge(char uName, char wName, int i);
int index(char vName);
void addFirst(Node* H, int i);
void topologicalSort();
bool isEmpty();
void enqueue(int i);
int dequeue();

struct Node {
	int element;
	Node* next;
};

struct Digraph {
	vertex* vertices;

	edge* edges;
};

struct Q_vertex {
	int* element;
	int front, rear;
};

struct vertex {
	char name;
	Node* outEdges;
	int pw;
	Node* inEdges;
	int inDegree;
};

struct edge {
	int origin;
	int destination;
};

int n, m, work;
int* topOrder;
Digraph G;
Q_vertex Q;



void buildGraph()
{
	vertex* v;
	int i, pw;
	char vName, uName, wName;
	scanf("%d %d %d", &work, &n, &m);

	G.vertices = (vertex*)malloc(sizeof(vertex) * n);

	for (i = 0;i < n;i++) {
		getchar();
		scanf("%c", &vName);
		scanf("%d", &pw);
		insertVertex(vName, i, pw);
	}

	G.edges = (edge*)malloc(sizeof(edge) * m);
	getchar();
	for (i = 0;i < m;i++) {
		scanf("%c %c", &uName, &wName);
		getchar();
		insertDirectedEdge(uName, wName, i);
	}

}

void insertVertex(char vName, int i, int pw)
{
	G.vertices[i].name = vName;
	G.vertices[i].outEdges = (Node*)malloc(sizeof(Node) * n);
	G.vertices[i].outEdges->next = NULL;
	G.vertices[i].pw = pw;
	G.vertices[i].inEdges = (Node*)malloc(sizeof(Node) * n);
	G.vertices[i].inEdges->next = NULL;
	G.vertices[i].inDegree = 0;
}

void insertDirectedEdge(char uName, char wName, int i)
{
	int u, w;
	u = index(uName);
	w = index(wName);

	G.edges[i].origin = u;
	G.edges[i].destination = w;

	addFirst(G.vertices[u].outEdges, i);
	addFirst(G.vertices[w].inEdges, i);
	G.vertices[w].inDegree++;

}

int index(char vName)
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
	Node* temp;
	Node* node = (Node*)malloc(sizeof(Node));

	node->element = i;
	node->next = NULL;
	temp = H->next;

	if (H->next == NULL)
	{
		H->next = node;
	}
	else {
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
	}

	return;
}

void topologicalSort()
{
	int* in, i, t, u, w;
	Node* temp_outedge;

	in = (int*)malloc(sizeof(int) * n);
	topOrder = (int*)malloc(sizeof(int) * (n + 1));

	Q.element = (int*)malloc(sizeof(int) * n);
	Q.front = -1;
	Q.rear = -1;

	for (i = 0;i < n;i++)
	{
		in[i] = G.vertices[i].inDegree;
		if (in[i] == 0)
			enqueue(i);
	}

	t = 1;

	while (!isEmpty(Q))
	{
		u = dequeue(Q);
		topOrder[t++] = u;
		temp_outedge = G.vertices[u].outEdges->next;

		while (temp_outedge != NULL)
		{
			w = G.edges[temp_outedge->element].destination;
			in[w] = in[w] - 1;

			if (in[w] == 0)
				enqueue(w);

			temp_outedge = temp_outedge->next;
		}
	}

	if (t <= n) topOrder[0] = 0;  //non -DAG

	else topOrder[0] = 1;

}

bool isEmpty()
{
	if (Q.front > Q.rear || Q.front == -1)
		return true;
	else
		return false;
}

void enqueue(int i)
{
	if (Q.front == -1)
	{
		Q.front++;
		Q.rear++;
		Q.element[Q.rear] = i;
	}
	else
		Q.element[++Q.rear] = i;
}

int dequeue()
{
	int temp = Q.front;
	Q.front++;
	return Q.element[temp];
}

int main()
{
	int i, sum = 0, count = 0;

	buildGraph();
	topologicalSort();

	if (topOrder[0] == 0)
		printf("-1\n");
	else
	{
		for (i = 1;i <= n;i++)
		{
			if (sum < work)
			{
				sum += G.vertices[topOrder[i]].pw;
				count++;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}



