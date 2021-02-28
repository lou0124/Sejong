//Prim-jarnik

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

bool inQueue(vertex* v);
bool isEmpty();
vertex* dequeue();
void enqueue(int element);
void PrimgJarnikMST(head_vertex* v_head);
void adjacentVertices(head_vertex* v_head, int node_num);
void insertEdge(head_vertex* v_head, head_edge* e_headn, int v_num, int w_num, int o);
void insertVertex(head_vertex* v_head, int o);

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


void PrimgJarnikMST(head_vertex* v_head)
{
	vertex* temp;
	incidence* itemp;
	vertex* u;
	vertex* z;
	edge* e;

	int sum = 0;
	int z_num;

	temp = v_head->start;
	while (temp != NULL)
	{
		temp->distance = 10000;
		temp->parent = NULL;
		temp = temp->next;
	}

	v_head->start->distance = 0;

	temp = v_head->start;

	while (temp != NULL)
	{
		enqueue(temp->distance);
		temp = temp->next;
	}

	while (!isEmpty(Q))
	{
		u = dequeue(Q);
		printf(" %d", u->node_num);
		if (isEmpty(Q)) break;

		itemp = u->head_incidence->next_incidence;

		while (itemp != NULL)
		{
			e = itemp->linked_edge;

			if (e->linked_vertex[0]->node_num == u->node_num)
				z = e->linked_vertex[1];
			else if (e->linked_vertex[1]->node_num == u->node_num)
				z = e->linked_vertex[0];

			if (inQueue(z) && (e->weight < z->distance))
			{
				z_num = z->distance;
				z->distance = e->weight;
				z->parent = e;
				replaceKey(z_num, e->weight);
			}
			itemp = itemp->next_incidence;
		}
	}

	temp = v_head->start;
	while (temp != NULL)
	{
		if (temp->parent != NULL)
			sum += temp->parent->weight;
		temp = temp->next;
	}

	printf("\n%d", sum);
}

void replaceKey(int z_num, int weight)
{
	node* temp = Q.front;
	while (temp != NULL)
	{
		if (temp->element == z_num)
		{
			if (temp->left == NULL && temp->right == NULL)
			{
				Q.front = NULL;
				Q.rear = NULL;
			}
			else if (temp->left == NULL) {
				Q.front = Q.front->right;
				Q.front->left = NULL;
			}
			else if (temp->right == NULL) {
				Q.rear = Q.rear->left;
				Q.rear->right = NULL;
			}
			else {
				temp->left->right = temp->right;
				temp->right->left = temp->left;
			}

			enqueue(weight);
			free(temp);
			break;
		}
		temp = temp->right;
	}
}

vertex* dequeue()
{
	vertex* temp;
	temp = v_head->start;

	while (temp != NULL)
	{
		if (temp->distance == Q.front->element)
		{
			Q.front = Q.front->right;
			if (Q.front != NULL)
				Q.front->left = NULL;
			return temp;
		}
		temp = temp->next;
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

bool inQueue(vertex* v)
{
	node* temp = Q.front;
	while (temp != NULL)
	{
		if (temp->element == v->distance)
			return true;
		temp = temp->right;
	}
	return false;
}

bool isEmpty()
{
	if (Q.front == NULL)
		return true;
	else
		return false;
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
	PrimgJarnikMST(v_head);

	return 0;
}*/