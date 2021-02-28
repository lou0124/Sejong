//AVL Æ®¸®

/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode {
	struct treeNode* parent;
	struct treeNode* LChild;
	struct treeNode* RChild;

	int key;
	int height;
}treeNode;


int findElement(treeNode* root, int key);
void insertItem(treeNode** root, int key);
bool heightUpdateAndBalanceCheck(treeNode* w);
void searchAndRepairAfterInsertion(treeNode** root, treeNode* w);
void restructure(treeNode** root, treeNode* x);
treeNode* treeSearch(treeNode* root, int key);
void removeElement(treeNode* root, int key);
void reduceExternal(treeNode* root, treeNode* z);
treeNode* sibling(treeNode* z);
bool isExternal(treeNode* Node);
treeNode* inOrderSucc(treeNode* Node);
void printPreorder(treeNode* root);



int findElement(treeNode* root, int key)
{
	if (isExternal(root)) {
		printf("X\n"); return;
	}

	else
	{
		if (root->key == key) {
			printf("%d\n", root->key);
			return root->key;
		}
		else if (key < root->key)
			return findElement(root->LChild, key);
		else
			return findElement(root->RChild, key);
	}
}


void insertItem(treeNode** root, int key)
{
	treeNode* temp = NULL;
	treeNode* newnode;
	treeNode* newnodeleft;
	treeNode* newnoderight;

	if ((*root) == NULL)
	{
		newnode = (treeNode*)malloc(sizeof(treeNode));
		newnodeleft = (treeNode*)malloc(sizeof(treeNode));
		newnoderight = (treeNode*)malloc(sizeof(treeNode));
		newnode->parent = NULL;
		newnode->key = key;
		newnode->height = 1;
		newnode->LChild = newnodeleft;
		newnode->RChild = newnoderight;
		newnodeleft->parent = newnode;
		newnoderight->parent = newnode;
		newnodeleft->LChild = NULL;
		newnodeleft->RChild = NULL;
		newnodeleft->height = 0;
		newnoderight->LChild = NULL;
		newnoderight->RChild = NULL;
		newnoderight->height = 0;
		*root = newnode;
	}

	else
	{
		temp = *root;
		while (!(isExternal(temp)))
		{
			if (key < temp->key) temp = temp->LChild;
			else                 temp = temp->RChild;
		}

		temp->key = key;
		newnodeleft = (treeNode*)malloc(sizeof(treeNode));
		newnoderight = (treeNode*)malloc(sizeof(treeNode));
		temp->LChild = newnodeleft;
		temp->RChild = newnoderight;
		newnodeleft->parent = temp;
		newnoderight->parent = temp;
		newnodeleft->LChild = NULL;
		newnodeleft->RChild = NULL;
		newnodeleft->height = 0;
		newnoderight->LChild = NULL;
		newnoderight->RChild = NULL;
		newnoderight->height = 0;
		
		searchAndRepairAfterInsertion(root, temp);
	}
}


bool heightUpdateAndBalanceCheck(treeNode* w)
{
	treeNode* l = w->LChild;
	treeNode* r = w->RChild;
	int balance;

	if (w == NULL) return true;

	w->height = ((r->height > l->height) ? r->height : l->height) + 1;
	balance = abs(r->height - l->height);

	return balance < 2;
}

void searchAndRepairAfterInsertion(treeNode **root, treeNode *w)
{
	treeNode* z = w;
	treeNode* y;
	treeNode* x;

	while (heightUpdateAndBalanceCheck(z))
	{
		if (z->parent == NULL) 
			return;
		z = z->parent;
	}

	if (z->LChild->height > z->RChild->height) y = z->LChild;
	else                                       y = z->RChild;

	if (y->LChild->height > y->RChild->height) x = y->LChild;
	else                                       x = y->RChild;

	restructure(root, x);
}

void restructure(treeNode **root, treeNode* x)
{
	treeNode* y = x->parent;
	treeNode* z = y->parent;
	treeNode* a, * b, * c;
	treeNode* t0, * t1, * t2, * t3;

	if (z->key < y->key && y->key < x->key)
	{
		a = z; b = y; c = x;
		t0 = a->LChild;
		t1 = b->LChild;
		t2 = c->LChild;
		t3 = c->RChild;
	}
	else if (z->key > y->key && y->key > x->key)
	{
		a = x; b = y; c = z;
		t0 = a->LChild;
		t1 = a->RChild;
		t2 = b->RChild;
		t3 = c->RChild;
	}
	else if (z->key < y->key && y->key > x->key)
	{
		a = z; b = x; c = y;
		t0 = a->LChild;
		t1 = b->LChild;
		t2 = b->RChild;
		t3 = c->RChild;
	}
	else
	{
		a = y; b = x; c = z;
		t0 = a->LChild;
		t1 = b->LChild;
		t2 = b->RChild;
		t3 = c->RChild;
	}

	if (z->parent == NULL) {
		*root = b;
		b->parent = NULL;
	}
	else if (z->parent->LChild == z){
		z->parent->LChild = b;
		b->parent = z->parent;
	}
	else {
		z->parent->RChild = b;
		b->parent = z->parent;
	}

	a->LChild = t0;
	a->RChild = t1;
	t0->parent = a;
	t1->parent = a;
	a->height = ((t0->height > t1->height) ? t0->height : t1->height) + 1;

	c->LChild = t2;
	c->RChild = t3;
	t2->parent = c;
	t3->parent = c;
	c->height = ((t2->height > t3->height) ? t2->height : t3->height) + 1;

	b->LChild = a;
	b->RChild = c;
	a->parent = b;
	c->parent = b;
	b->height = ((a->height > c->height) ? a->height : c->height) + 1;
}

treeNode* treeSearch(treeNode* root, int key)
{
	if (isExternal(root))
		return root;
	else
	{
		if (root->key == key)
			return root;
		else if (key < root->key)
			return treeSearch(root->LChild, key);
		else
			return treeSearch(root->RChild, key);
	}
}


void removeElement(treeNode* root, int key)
{
	treeNode* w;
	treeNode* y;
	treeNode* z;

	w = treeSearch(root, key);

	if (isExternal(w)) {
		printf("X\n");
		return;
	}
	else
		printf("%d\n", w->key);

	z = w->LChild;

	if (!isExternal(z))
		z = w->RChild;

	if (isExternal(z))
		reduceExternal(root, z);
	else
	{
		z = inOrderSucc(w);
		y = z->parent;
		w->key = y->key;
		reduceExternal(root, z);
	}
}


void reduceExternal(treeNode* root, treeNode* z)
{
	treeNode* g;
	treeNode* w;
	treeNode* zs;

	w = z->parent;
	zs = sibling(z);

	if (w->parent == NULL)
	{
		root = zs;
		zs->parent = NULL;
	}
	else
	{
		g = w->parent;
		zs->parent = g;
		if (g->LChild == w)
			g->LChild = zs;
		else
			g->RChild = zs;
	}
	free(z);
	free(w);
}


treeNode* sibling(treeNode* z)
{
	if (z->parent->LChild == z)
		return z->parent->RChild;
	else if (z->parent->RChild == z)
		return z->parent->LChild;
}


bool isExternal(treeNode* Node)
{
	if (Node->LChild == NULL && Node->RChild == NULL)
		return true;
	else
		return false;
}


treeNode* inOrderSucc(treeNode* Node)
{
	treeNode* temp = Node->RChild;

	while (temp->LChild != NULL)
		temp = temp->LChild;

	return temp;
}


void printPreorder(treeNode* root)
{
	if (!isExternal(root))
	{
		printf(" %d", root->key);
		printPreorder(root->LChild);
		printPreorder(root->RChild);
	}
}


int main()
{
	treeNode* root = NULL;
	char selectfunc;
	int key;

	while (true)
	{
		scanf("%c", &selectfunc);

		switch (selectfunc)
		{
		case 'i':
			scanf("%d", &key);
			insertItem(&root, key); break;
		case 'd':
			scanf("%d", &key);
			removeElement(root, key); break;
		case 's':
			scanf("%d", &key);
			findElement(root, key); break;
		case 'p':
			printPreorder(root);
			printf("\n", root->key);break;
		case 'q':
			return 0;
		}

	}

	return 0;
}*/