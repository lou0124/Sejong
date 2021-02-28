//BFS (인접행렬)

/*#include <stdio.h>
#include <stdlib.h>

typedef struct head_vertex head_vertex;
typedef struct head_edge head_edge;
typedef struct vertex vertex;
typedef struct incidence incidence;
typedef struct edge edge;

struct head_vertex {
	vertex* start;
};

struct head_edge {
	edge* start;
};

struct vertex {
	incidence* head_incidence;
	int index;
	char state[8];
	int node_num;
	vertex* next;
};

struct incidence {
	edge* linked_edge;
	incidence* next_incidence;
};

struct edge {
	vertex* linked_vertex[2];
	char state[6];
	edge* next_edge;
};

vertex* findVertex(head_vertex* v_head, int node_num)
{
	vertex* vtemp = v_head->start;
	while (vtemp != NULL)
	{
		if (vtemp->node_num == node_num)
			return vtemp;
		vtemp = vtemp->next;
	}
	return NULL;
}

void insertVertex(head_vertex* v_head, int o)
{
	vertex* vtemp;
	vertex* vnode = (vertex*)malloc(sizeof(vertex));
	vnode->index = o - 1;
	vnode->node_num = o;
	strcpy(vnode->state, "Fresh");
	vnode->next = NULL;

	if (v_head->start == NULL)
		v_head->start = vnode;
	else {
		vtemp = v_head->start;

		while (vtemp->next != NULL)
			vtemp = vtemp->next;
		vtemp->next = vnode;
	}
}

void insertEdge(head_vertex* v_head, head_edge* e_headn, edge*** adj_mat, int v_num, int w_num)
{
	vertex* v;
	vertex* w;
	edge* enode = (edge*)malloc(sizeof(edge));
	edge* etemp;

	v = findVertex(v_head, v_num);
	w = findVertex(v_head, w_num);

	enode->linked_vertex[0] = v;
	enode->linked_vertex[1] = w;
	strcpy(enode->state, "Fresh");
	enode->next_edge = NULL;

	if (v_num != w_num)
		enode->linked_vertex[1] = w;

	if (e_headn->start == NULL)
		e_headn->start = enode;
	else
	{
		etemp = e_headn->start;
		while (etemp->next_edge != NULL)
			etemp = etemp->next_edge;

		etemp->next_edge = enode;
	}

	adj_mat[v_num - 1][w_num - 1] = enode;
	adj_mat[w_num - 1][v_num - 1] = enode;
}


void addLast(head_vertex* L, vertex* v)
{
	vertex* vtemp;
	if (L->start == NULL)
	{
		L->start = v;
		v->next = NULL;
	}
	else
	{
		vtemp = L->start;
		while (vtemp->next != NULL)
			vtemp = vtemp->next;

		vtemp->next = v;
		v->next = NULL;
	}
}

void BFS(vertex* v, edge*** adj_mat, int n)
{
	int i, j;
	vertex* w, * vtemp;
	edge* etemp;
	head_vertex** L = (head_vertex * *)malloc(sizeof(head_vertex*));

	L[0] = (head_vertex*)malloc(sizeof(head_vertex));
	L[0]->start = NULL;
	addLast(L[0], v);

	strcpy(v->state, "Visited");
	printf("%d\n", v->node_num);

	i = 0;
	while (L[i]->start != NULL)
	{
		L[i + 1] = (head_vertex*)malloc(sizeof(head_vertex));
		L[i + 1]->start = NULL;
		vtemp = L[i]->start;
		while (vtemp != NULL)
		{
			for (j = 0;j < n;j++)
			{
				etemp = adj_mat[vtemp->index][j];
				if (etemp != NULL)
				{
					if (strcmp(etemp->state, "Fresh") == 0)
					{
						if (etemp->linked_vertex[0] == vtemp && etemp->linked_vertex[1] != vtemp)
							w = etemp->linked_vertex[1];
						else
							w = etemp->linked_vertex[0];
						if (strcmp(w->state, "Fresh") == 0)
						{
							strcpy(etemp->state, "Tree");
							strcpy(w->state, "Visited");
							printf("%d\n", w->node_num);
							addLast(L[i + 1], w);
						}
						else
							strcpy(etemp->state, "Cross");
					}
				}
			}
			vtemp = vtemp->next;
		}
		i++;
	}
}

int main()
{
	int n, m, s, i, j;
	int v, w;

	head_vertex* v_head = (head_vertex*)malloc(sizeof(head_vertex));
	head_edge* e_head = (head_edge*)malloc(sizeof(head_edge));
	edge*** adj_mat;

	vertex* start;
	v_head->start = NULL;
	e_head->start = NULL;

	scanf("%d %d %d", &n, &m, &s);

	for (i = 1;i <= n;i++)
		insertVertex(v_head, i);

	adj_mat = (edge * **)malloc(sizeof(edge * *) * n);

	for (i = 0;i < n;i++)
		adj_mat[i] = (edge * *)malloc(sizeof(edge*) * n);

	for (i = 0;i < n;i++)
		for (j = 0;j < n;j++)
			adj_mat[i][j] = NULL;

	for (i = 0;i < m;i++)
	{
		scanf("%d %d", &v, &w);
		insertEdge(v_head, e_head, adj_mat, v, w);
	}

	start = findVertex(v_head, s);
	BFS(start, adj_mat, n);

	return 0;
}*/