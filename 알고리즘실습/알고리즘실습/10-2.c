//인접행렬 구현

/*#include <stdio.h>
#include <stdlib.h>

typedef struct head_vertex head_vertex;
typedef struct head_edge head_edge;
typedef struct vertex vertex;
typedef struct edge edge;

struct head_vertex {
	vertex* start;
};

struct head_edge {
	edge* start;
};

struct vertex {
	int index;
	int node_num;
	vertex* next;
};

struct edge {
	vertex* linked_vertex[2];
	int weight;
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

void insertEdge(head_vertex* v_head, head_edge* e_headn, edge* adj_mat[6][6], int v_num, int w_num, int o)
{
	vertex* v;
	vertex* w;
	edge* enode = (edge*)malloc(sizeof(edge));
	edge* etemp;

	v = findVertex(v_head, v_num);
	w = findVertex(v_head, w_num);

	enode->linked_vertex[0] = v;
	enode->linked_vertex[1] = NULL;
	enode->weight = o;
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

void adjacentVertices(head_vertex* v_head, edge* adj_mat[6][6], int node_num)
{
	vertex* vtemp = v_head->start;
	edge* etemp;
	int i, j, k;

	for (i = 0;i < 6;i++)
	{
		if (i == node_num - 1)
		{
			for (j = 0;j < 6;j++)
				if (adj_mat[i][j] != NULL)
				{
					if (adj_mat[i][j]->linked_vertex[1] == NULL)
					{
						printf(" %d %d", adj_mat[i][j]->linked_vertex[0]->node_num, adj_mat[i][j]->weight);
					}
					else {
						for (k = 0;k < 2;k++)
							if (adj_mat[i][j]->linked_vertex[k]->node_num != node_num)
								printf(" %d %d", adj_mat[i][j]->linked_vertex[k]->node_num, adj_mat[i][j]->weight);
					}
				}
			printf("\n");
			return;
		}
	}

	printf("-1\n");
}

edge* removeEdge(head_edge* e_head, int v, int w)
{
	edge* now_edge = e_head->start;
	edge* pre_edge = e_head->start;

	if ((now_edge->linked_vertex[0]->node_num == v && now_edge->linked_vertex[1] == NULL) ||
		(now_edge->linked_vertex[0]->node_num == v && now_edge->linked_vertex[1]->node_num == w) ||
		(now_edge->linked_vertex[0]->node_num == w && now_edge->linked_vertex[1]->node_num == v))
	{
		e_head->start = now_edge->next_edge;
		return now_edge;
	}


	while (now_edge != NULL)
	{
		now_edge = now_edge->next_edge;
		if (now_edge == NULL) break;

		if (now_edge->linked_vertex[0]->node_num == v && now_edge->linked_vertex[1] == NULL && v == w)
		{
			pre_edge->next_edge = now_edge->next_edge;
			return now_edge;
		}
		else if (now_edge->linked_vertex[1] != NULL)
		{
			if ((now_edge->linked_vertex[0]->node_num == v && now_edge->linked_vertex[1]->node_num == w) ||
				(now_edge->linked_vertex[0]->node_num == w && now_edge->linked_vertex[1]->node_num == v))
			{
				pre_edge->next_edge = now_edge->next_edge;
				return now_edge;
			}
		}
		pre_edge = now_edge;
	}

	return now_edge;
}

void makeWeight(head_vertex* v_head, head_edge* e_head, edge* adj_mat[6][6], int v_num, int w_num, int weight)
{
	vertex* test_v, * test_w;
	vertex* vtemp = v_head->start;
	edge* etemp;
	edge* pe;
	edge* e;

	int i;

	test_v = findVertex(v_head, v_num);
	test_w = findVertex(v_head, w_num);
	if (test_v == NULL || test_w == NULL) {
		printf("-1\n");
		return;
	}
	if (weight == 0)
	{
		e = removeEdge(e_head, v_num, w_num);
		if (e == NULL) {
			printf("-1\n");
			return;
		}
		adj_mat[v_num - 1][w_num - 1] = NULL;
		adj_mat[w_num - 1][v_num - 1] = NULL;
		free(e);
	}

	else {
		insertEdge(v_head, e_head, adj_mat, v_num, w_num, weight);
		//adj_mat[v_num - 1][w_num - 1]->weight = weight;
	}
}


int main()
{
	int v, w, weight, node_num, i, j;
	char select;

	head_vertex* v_head = (head_vertex*)malloc(sizeof(head_vertex));
	head_edge* e_head = (head_edge*)malloc(sizeof(head_edge));
	edge* adj_mat[6][6];

	v_head->start = NULL;
	e_head->start = NULL;

	for (i = 0;i < 6;i++)
		for (j = 0;j < 6;j++)
			adj_mat[i][j] = NULL;

	insertVertex(v_head, 1);
	insertVertex(v_head, 2);
	insertVertex(v_head, 3);
	insertVertex(v_head, 4);
	insertVertex(v_head, 5);
	insertVertex(v_head, 6);;

	insertEdge(v_head, e_head, adj_mat, 1, 2, 1);
	insertEdge(v_head, e_head, adj_mat, 1, 3, 1);
	insertEdge(v_head, e_head, adj_mat, 1, 4, 1);
	insertEdge(v_head, e_head, adj_mat, 1, 6, 2);
	insertEdge(v_head, e_head, adj_mat, 2, 3, 1);
	insertEdge(v_head, e_head, adj_mat, 3, 5, 4);
	insertEdge(v_head, e_head, adj_mat, 5, 5, 4);
	insertEdge(v_head, e_head, adj_mat, 5, 6, 3);

	while (1)
	{
		scanf("%c", &select);
		switch (select)
		{
		case 'a':
			scanf("%d", &node_num);
			adjacentVertices(v_head, adj_mat, node_num);
			break;
		case 'm':
			scanf("%d %d %d", &v, &w, &weight);
			makeWeight(v_head, e_head, adj_mat, v, w, weight);
			break;
		case 'q':
			return 0;
		}
	}

	return 0;
}*/