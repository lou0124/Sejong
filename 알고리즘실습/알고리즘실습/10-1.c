//인접리스트 구현

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
	int node_num;
	vertex* next;
};

struct incidence {
	edge* linked_edge;
	incidence* next_incidence;
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

edge* removeEdge(head_edge* e_head, int v, int w)
{
	edge* now_edge = e_head->start;
	edge* pre_edge = e_head->start;

	if ((now_edge->linked_vertex[0]->node_num == v && now_edge->linked_vertex[1]->node_num == w) ||
		(now_edge->linked_vertex[0]->node_num == w && now_edge->linked_vertex[1]->node_num == v))
	{
		e_head->start = now_edge->next_edge;
		return now_edge;
	}


	while (now_edge != NULL)
	{
		now_edge = now_edge->next_edge;
		if (now_edge == NULL) break;


		if ((now_edge->linked_vertex[0]->node_num == v && now_edge->linked_vertex[1]->node_num == w) ||
			(now_edge->linked_vertex[0]->node_num == w && now_edge->linked_vertex[1]->node_num == v))
		{
			pre_edge->next_edge = now_edge->next_edge;
			return now_edge;
		}

		pre_edge = now_edge;
	}

	return now_edge;
}

void removeIncidence(edge* e, vertex* v)
{
	incidence* preIncidence = v->head_incidence;
	incidence* nowIncidence = v->head_incidence;
	while (nowIncidence != NULL)
	{
		nowIncidence = nowIncidence->next_incidence;
		if (nowIncidence->linked_edge == e)
		{
			preIncidence->next_incidence = nowIncidence->next_incidence;
			free(nowIncidence);
			return;
		}
		preIncidence = nowIncidence;
	}
}

void insertVertex(head_vertex* v_head, int o)
{
	vertex* vtemp;
	vertex* vnode = (vertex*)malloc(sizeof(vertex));
	incidence* inode = (incidence*)malloc(sizeof(incidence));
	inode->next_incidence = NULL;
	vnode->head_incidence = inode;
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

void insertEdge(head_vertex* v_head, head_edge* e_headn, int v_num, int w_num, int o)
{

	vertex* v;
	vertex* w;
	incidence* temp_Vincidence;
	incidence* temp_Wincidence;
	incidence* pre_Vincidence;
	incidence* pre_Wincidence;
	incidence* new_Vinode = (incidence*)malloc(sizeof(incidence));
	incidence* new_Winode = (incidence*)malloc(sizeof(incidence));
	edge* enode = (edge*)malloc(sizeof(edge));
	edge* etemp;

	v = findVertex(v_head, v_num);
	w = findVertex(v_head, w_num);
	temp_Vincidence = v->head_incidence;
	temp_Wincidence = w->head_incidence;
	pre_Vincidence = v->head_incidence;
	pre_Wincidence = w->head_incidence;

	enode->linked_vertex[0] = v;
	enode->linked_vertex[1] = w;
	enode->weight = o;
	enode->next_edge = NULL;

	new_Vinode->linked_edge = enode;
	new_Vinode->next_incidence = NULL;


	while (temp_Vincidence->next_incidence != NULL)
	{
		temp_Vincidence = temp_Vincidence->next_incidence;
		etemp = temp_Vincidence->linked_edge;
		if ((etemp->linked_vertex[0]->node_num == v_num && etemp->linked_vertex[1]->node_num > w_num) ||
			(etemp->linked_vertex[0]->node_num > w_num && etemp->linked_vertex[1]->node_num == v_num))
		{
			pre_Vincidence->next_incidence = new_Vinode;
			new_Vinode->next_incidence = temp_Vincidence;
			break;
		}
		pre_Vincidence = temp_Vincidence;
	}

	if (temp_Vincidence->next_incidence == NULL && new_Vinode->next_incidence == NULL)
		temp_Vincidence->next_incidence = new_Vinode;


	if (v_num != w_num)
	{
		new_Winode->linked_edge = enode;
		new_Winode->next_incidence = NULL;

		while (temp_Wincidence->next_incidence != NULL)
		{
			temp_Wincidence = temp_Wincidence->next_incidence;
			etemp = temp_Wincidence->linked_edge;
			if ((etemp->linked_vertex[0]->node_num == w_num && etemp->linked_vertex[1]->node_num > v_num) ||
				(etemp->linked_vertex[0]->node_num > v_num && etemp->linked_vertex[1]->node_num == w_num))
			{
				pre_Wincidence->next_incidence = new_Winode;
				new_Winode->next_incidence = temp_Wincidence;
				break;
			}
			pre_Wincidence = temp_Wincidence;

		}

	}

	if (temp_Wincidence->next_incidence == NULL && new_Winode->next_incidence == NULL)
		temp_Wincidence->next_incidence = new_Winode;

	if (e_headn->start == NULL)
		e_headn->start = enode;
	else
	{
		etemp = e_headn->start;
		while (etemp->next_edge != NULL)
			etemp = etemp->next_edge;

		etemp->next_edge = enode;
	}
}


void adjacentVertices(head_vertex* v_head, int node_num)
{
	vertex* vtemp = v_head->start;
	incidence* itemp;
	edge* etemp;
	int i;

	while (vtemp != NULL)
	{
		if (vtemp->node_num == node_num)
		{
			itemp = vtemp->head_incidence->next_incidence;
			while (itemp != NULL)
			{
				etemp = itemp->linked_edge;

				if (etemp->linked_vertex[0]->node_num == etemp->linked_vertex[1]->node_num)
				{
					printf(" %d %d", etemp->linked_vertex[0]->node_num, etemp->weight);
				}
				else
				{
					for (i = 0;i < 2;i++)
					{
						if (etemp->linked_vertex[i]->node_num != node_num)
							printf(" %d %d", etemp->linked_vertex[i]->node_num, etemp->weight);
					}
				}
				itemp = itemp->next_incidence;
			}
			printf("\n");
			return;
		}
		vtemp = vtemp->next;
	}
	if (vtemp == NULL) printf("-1\n");
}

void makeWeight(head_vertex* v_head, head_edge* e_head, int v_num, int w_num, int weight)
{
	vertex* test_v, * test_w;
	vertex* vtemp = v_head->start;
	incidence* itemp;
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
		removeIncidence(e, e->linked_vertex[0]);
		if (e->linked_vertex[0] != e->linked_vertex[1])
			removeIncidence(e, e->linked_vertex[1]);
		free(e);
	}

	else {
		while (vtemp != NULL)
		{
			if (vtemp->node_num == v_num)
			{
				itemp = vtemp->head_incidence->next_incidence;
				while (itemp != NULL)
				{
					etemp = itemp->linked_edge;
					if ((etemp->linked_vertex[0]->node_num == v_num && etemp->linked_vertex[1]->node_num == w_num) ||
						(etemp->linked_vertex[0]->node_num == w_num && etemp->linked_vertex[1]->node_num == v_num))
					{
						etemp->weight = weight;
						return;
					}

					itemp = itemp->next_incidence;
				}
				if (itemp == NULL)
					insertEdge(v_head, e_head, v_num, w_num, weight);
			}
			vtemp = vtemp->next;
		}
	}
}

int main()
{
	int node_num;
	int v, w, weight;
	char select;

	head_vertex* v_head = (head_vertex*)malloc(sizeof(head_vertex));
	head_edge* e_head = (head_edge*)malloc(sizeof(head_edge));
	v_head->start = NULL;
	e_head->start = NULL;

	insertVertex(v_head, 1);
	insertVertex(v_head, 2);
	insertVertex(v_head, 3);
	insertVertex(v_head, 4);
	insertVertex(v_head, 5);
	insertVertex(v_head, 6);;

	insertEdge(v_head, e_head, 1, 2, 1);
	insertEdge(v_head, e_head, 1, 3, 1);
	insertEdge(v_head, e_head, 1, 4, 1);
	insertEdge(v_head, e_head, 1, 6, 2);
	insertEdge(v_head, e_head, 2, 3, 1);
	insertEdge(v_head, e_head, 3, 5, 4);
	insertEdge(v_head, e_head, 5, 5, 4);
	insertEdge(v_head, e_head, 5, 6, 3);

	while (1)
	{
		scanf("%c", &select);
		switch (select)
		{
		case 'a':
			scanf("%d", &node_num);
			adjacentVertices(v_head, node_num);
			break;
		case 'm':
			scanf("%d %d %d", &v, &w, &weight);
			makeWeight(v_head, e_head, v, w, weight);
			break;
		case 'q':
			return 0;
		}
	}

	return 0;
}*/