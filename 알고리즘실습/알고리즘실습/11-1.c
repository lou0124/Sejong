//DFS

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

void insertEdge(head_vertex* v_head, head_edge* e_headn, int v_num, int w_num)
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
	strcpy(enode->state, "Fresh");
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


void DFS(vertex* v)
{
	vertex* w;
	incidence* itemp;
	edge* etemp;
	strcpy(v->state, "Visited");
	printf("%d\n", v->node_num);

	itemp = v->head_incidence->next_incidence;

	while (itemp != NULL)
	{
		etemp = itemp->linked_edge;
		if (strcmp(etemp->state, "Fresh") == 0)
		{
			if (etemp->linked_vertex[0] == v && etemp->linked_vertex[1] != v)
				w = etemp->linked_vertex[1];
			else
				w = etemp->linked_vertex[0];
			
			if (strcmp(w->state, "Fresh") == 0)
			{
				strcpy(etemp->state, "Tree");
				DFS(w);
			}
			else 
				strcpy(etemp->state, "Back");
		}
		itemp = itemp->next_incidence;
	}
}

int main()
{
	int n, m, s, i;
	int node_num;
	int v, w, weight;
	char select;

	head_vertex* v_head = (head_vertex*)malloc(sizeof(head_vertex));
	head_edge* e_head = (head_edge*)malloc(sizeof(head_edge));
	vertex* start;
	v_head->start = NULL;
	e_head->start = NULL;

	scanf("%d %d %d", &n, &m, &s);
	for (i = 1;i <= n;i++)
		insertVertex(v_head, i);

	for (i = 0;i < m;i++)
	{
		scanf("%d %d", &v, &w);
		insertEdge(v_head, e_head, v, w);
	}


	start = findVertex(v_head, s);
	DFS(start);

	return 0;
}*/