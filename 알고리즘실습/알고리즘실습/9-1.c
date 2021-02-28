//분리 연쇄법 해쉬 테이블

/*#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void insertKey(Node *hashTable, int key, int M)
{
	
	Node *newnode;
	int bucket;
	bucket = key % M;

	newnode = (Node*)malloc(sizeof(Node));
	newnode->data = key;
	newnode->next = hashTable[bucket].next;
	hashTable[bucket].next = newnode;
}

int searchKey(Node* hashTable, int key, int M)
{
	Node* temp;
	int bucket, count = 0;

	bucket = key % M;
	temp = &hashTable[bucket];
	while (temp->next != NULL) 
	{
		temp = temp->next;
		count++;
		if (temp->data == key) 
			return count;
	}
	return 0;
}

int deleteKey(Node* hashTable, int key, int M)
{
	Node* first, *last;
	int bucket, count = 0;

	bucket = key % M;
	first = &hashTable[bucket];
	last = first;
	while (first->next != NULL) 
	{
		first = first->next;
		count++;
		if (first->data == key) 
		{
			last->next = first->next;
			free(first);
			return count;
		}
		last = first;
	}
	return 0;
}

void printHashtable(Node *hashTable, int M)
{
	Node* temp;
	int i;

	for (i = 0;i < M;i++) 
	{
		temp = &hashTable[i];
		while (temp->next != NULL)
		{
			temp = temp->next;
			printf(" %d", temp->data);
		}
	}
	printf("\n");
}

int main()
{
	Node* hashTable;
	int i, M, key;
	char ins;
	scanf("%d", &M);

	hashTable = (Node*)malloc(sizeof(Node) * M);
	for (i = 0;i < M;i++) 
	{
		hashTable[i].data = i;
		hashTable[i].next = NULL;
	}

	while (1)
	{
		scanf("%c", &ins);
		switch (ins)
		{
		case 'i':
			scanf("%d", &key); 
			insertKey(hashTable, key, M);
			break;
		case 's':
			scanf("%d", &key); 
			printf("%d\n", searchKey(hashTable, key, M));
			break;
		case 'd':
			scanf("%d", &key);
			printf("%d\n", deleteKey(hashTable, key, M));
			break;
		case 'p':
			printHashtable(hashTable, M);
			break;
		case 'e':
			return 0;
		}
	}
	return 0;
}*/