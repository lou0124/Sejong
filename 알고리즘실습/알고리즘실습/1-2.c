// r, l 입력하면 노드 탐색

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct treeNode {
	struct treeNode* left;
	int data;
	struct treeNode* right;
}treeNode;

treeNode* makeNode(int data)
{
	treeNode* node = (treeNode*)malloc(sizeof(treeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
treeNode* d;

treeNode* preorder(treeNode* root, int data)
{
	if(root)
	{
		if (root->data == data) d = root;
		preorder(root->left, data);
		preorder(root->right, data);
	}
}

treeNode* makeTree(treeNode* root, int x, int y, int z)
{
	treeNode * l, * r;

	if (root == NULL)
	{
		root = makeNode(x);
		d = root;
	}
	else
		preorder(root, x);

	if (y != 0) 
	{
		l = makeNode(y);
		d->left = l;
	}
	if (z != 0)
	{
		r = makeNode(z);
		d->right = r;
	}
	return root;
}

void search(treeNode* root,char* str)
{
	treeNode* p = root;
	int i = 0;

	if(p != NULL)
	   printf(" %d", p->data);

	while (str[i] != '\0')
	{
		if (str[i] == 'L') p = p->left;
		else if (str[i] == 'R') p = p->right;
		printf(" %d", p->data);
		i++;
	}
	printf("\n");
}

int main()
{
	treeNode* root = NULL;
	int n_num, s_num, i, d, l, r;
	char str[100];
	
	scanf("%d", &n_num);
	for (i = 0;i < n_num;i++)
	{
		scanf("%d %d %d", &d, &l, &r);
		root = makeTree(root, d, l, r);
	}

	scanf("%d", &s_num);
	for (i = 0;i < s_num;i++)
	{
		scanf("%s", str);
		search(root, str);
	}

	return 0;
}
*/