//Kruskal
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct head_vertex head_vertex;
typedef struct head_edge head_edge;
typedef struct vertex vertex;
typedef struct incidence incidence;
typedef struct edge edge;
typedef struct Q_vertex Q_vertex;
typedef struct node node;

struct Q_vertex {
	node* front;
	node* rear;
};

struct node {
	int element;
	node* left;
	node* right;
};

struct head_vertex {
	vertex* start;
};

struct head_edge {
	edge* start;
};

struct vertex {
	incidence* head_incidence;
	int node_num;
	int distance;
	int Sack;
	edge* parent;
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

Q_vertex Q;
int n, m;
head_vertex* v_head;
head_edge* e_head;
node* T;

edge* dequeue();
void enqueue(int element);
void KruskalMST(head_vertex* v_head);
void insertEdge(head_vertex* v_head, head_edge* e_headn, int v_num, int w_num, int o);
void insertVertex(head_vertex* v_head, int o);
void addedge(edge* e);
int edgeNum();

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

void KruskalMST(head_vertex* v_head)
{
	vertex* temp;
	edge* etemp;

	incidence* itemp;
	vertex* u;
	vertex* v;
	vertex* z;
	edge* e;

	int sum = 0;
	int save;

	temp = v_head->start;
	while (temp != NULL)
	{
		temp->Sack = temp->node_num;
		temp = temp->next;
	}

	etemp = e_head->start;

	while (etemp != NULL)
	{
		enqueue(etemp->weight);
		etemp = etemp->next_edge;
	}

	T = NULL;
	
	while (edgeNum() < (n - 1))
	{
		e = dequeue();	
		u = e->linked_vertex[0];
		v = e->linked_vertex[1];

		if (u->Sack != v->Sack)
		{
			addedge(e);
			printf(" %d", e->weight);
			sum += e->weight;
			temp = v_head->start;

			if (u->Sack > v->Sack)
			{
				save = u->Sack;
				while (temp != NULL)
				{
					if (temp->Sack == save)
						temp->Sack = v->Sack;
					temp = temp->next;
				}
			}
			else
			{
				save = v->Sack;
				while (temp != NULL)
				{
					if (temp->Sack == save)
						temp->Sack = u->Sack;
					temp = temp->next;
				}
			}
		}
	}
	printf("\n%d", sum);
}

int edgeNum()
{
	int i = 0;
	node* temp = T;
	while (temp != NULL)
	{
		i++;
		temp = temp->right;
	}
	return i;
}

void addedge(edge* e)
{
	node* temp;
	node* newnode = (node *)malloc(sizeof(node));
	newnode->element = e->weight;
	newnode->right = NULL;

	if (T == NULL)
	{
		T = newnode;
	}
	else
	{
		newnode->right = T;
		T = newnode;
	}
}

edge* dequeue()
{
	edge* temp;
	temp = e_head->start;

	while (temp != NULL)
	{
		if (temp->weight == Q.front->element)
		{
			Q.front = Q.front->right;
			if (Q.front != NULL)
				Q.front->left = NULL;
			return temp;
		}
		temp = temp->next_edge;
	}
}


void enqueue(int element)
{
	node* temp;
	node* newnode = (node*)malloc(sizeof(node));
	newnode->element = element;
	newnode->right = NULL;
	newnode->left = NULL;


	if (Q.front == NULL)
	{
		Q.front = newnode;
		Q.rear = newnode;
	}

	else if (Q.front->element > newnode->element)
	{
		newnode->right = Q.front;
		Q.front->left = newnode;
		Q.front = newnode;
	}

	else
	{
		temp = Q.front;
		while (temp != NULL)
		{
			if (temp->element > newnode->element)
			{
				temp->left->right = newnode;
				newnode->left = temp->left;
				newnode->right = temp;
				temp->left->right = newnode;
				temp->left = newnode;
				break;
			}
			temp = temp->right;
		}
		if (temp == NULL)
		{
			Q.rear->right = newnode;
			newnode->left = Q.rear;
			Q.rear = newnode;
		}
	}
}

int main()
{
	int i;
	int node_num;
	int v, w, weight;

	v_head = (head_vertex*)malloc(sizeof(head_vertex));
	e_head = (head_edge*)malloc(sizeof(head_edge));
	v_head->start = NULL;
	e_head->start = NULL;
	Q.front = NULL;
	Q.rear = NULL;

	scanf("%d %d", &n, &m);

	for (i = 1;i <= n;i++)
		insertVertex(v_head, i);

	for (i = 0;i < m;i++)
	{
		scanf("%d %d %d", &v, &w, &weight);
		insertEdge(v_head, e_head, v, w, weight);
	}

	KruskalMST(v_head);

	return 0;
}*/