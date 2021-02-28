//이진 탐색 트리

/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode {
	struct treeNode* parent;
	struct treeNode* LChild;
	struct treeNode* RChild;

	int key;
}treeNode;

treeNode* root = NULL;

int findElement(treeNode* root, int key);
void insertItem(int key);
treeNode* treeSearch(treeNode* root, int key);
void removeElement( int key);
void reduceExternal(treeNode* z);
treeNode* sibling(treeNode* z);
bool isExternal(treeNode* Node);
treeNode* inOrderSucc(treeNode* Node);
void printPreorder(treeNode *root);



int findElement(treeNode *root, int key)
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


void insertItem( int key)
{
	treeNode* temp = NULL;
	treeNode* newnode;
	treeNode* newnodeleft;
	treeNode* newnoderight;

	if (root == NULL)
	{
		newnode = (treeNode*)malloc(sizeof(treeNode));
		newnodeleft = (treeNode*)malloc(sizeof(treeNode));
		newnoderight = (treeNode*)malloc(sizeof(treeNode));
		newnode->parent = NULL;
		newnode->key = key;
		newnode->LChild = newnodeleft;
		newnode->RChild = newnoderight;
		newnodeleft->parent = newnode;
		newnoderight->parent = newnode;
		newnodeleft->LChild = NULL;
		newnodeleft->RChild = NULL;
		newnoderight->LChild = NULL;
		newnoderight->RChild = NULL;
		root = newnode;
	}

	else
	{
		temp = root;
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
		newnoderight->LChild = NULL;
		newnoderight->RChild = NULL;
	}
}


treeNode* treeSearch(treeNode *root, int key)
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


void removeElement(int key)
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
		reduceExternal(z);
	else
	{
		z = inOrderSucc(w);
		y = z->parent;
		w->key = y->key;
		reduceExternal(z);
	}

}


void reduceExternal(treeNode* z)
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
	char selectfunc;
	int key;

	while (true)
	{
		scanf("%c", &selectfunc);

		switch (selectfunc)
		{
		case 'i':
			scanf("%d", &key);
			insertItem(key); break;
		case 'd':
			scanf("%d", &key);
			removeElement(key); break;
		case 's':
			scanf("%d", &key);
			findElement(root, key); break;
		case 'p':
			printPreorder(root);
			printf("\n");break;
		case 'q':
			return 0;
		}
	}
	return 0;
}*/