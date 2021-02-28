//이중연결리스트 구현


/*#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node* prev;
	char elem;
	struct Node* next;
}Node;


Node* createList()
{
	Node* H;
	Node* T;
	H = (Node*)malloc(sizeof(Node));
	T = (Node*)malloc(sizeof(Node));
	H->prev = NULL;
	T->next = NULL;
	H->next = T;
	T->prev = H;

	return H;
}

Node* get(Node* list, int r)
{
	int i;
	Node* temp;
	temp = list;

	for (i = 0;i < r;i++) {
		temp = temp->next;
		if (temp->next == NULL) {
			printf("invalid position\n");
			return NULL;
		}
	}

	return temp;
}

void add(Node* list, int r, char e)
{
	Node* addNode;
	Node* temp;
	int i;

	temp = list;
	addNode = (Node*)malloc(sizeof(Node));
	addNode->elem = e;

	for (i = 1;i < r;i++) {
		temp = temp->next;
		if (temp->next == NULL) {
			printf("invalid position\n");
			return;
		}
	}

	addNode->next = temp->next;
	addNode->prev = temp;
	temp->next = addNode;
	addNode->next->prev = addNode;
}


void delete(Node* list, int r)
{
	Node* old;
	old = get(list, r);

	if (old == NULL) return;

	old->prev->next = old->next;
	old->next->prev = old->prev;

	free(old);
}

void print(Node* list)
{
	Node* p;
	p = list->next;
	while (p->next != NULL)
	{
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	char type, e;
	int num, r, i;
	Node* list;
	list = createList();

	scanf_s("%d", &num);
	getchar();

	for (i = 0;i < num;i++) {
		scanf_s("%c", &type);
		getchar();
		switch (type)
		{
		case 'A':
			scanf_s("%d %c", &r, &e); getchar();
			add(list, r, e); break;
		case 'D':
			scanf_s("%d", &r); getchar();
			delete(list, r); break;
		case 'G':
			scanf_s("%d", &r); getchar();
			if (get(list, r) != NULL) 
				printf("%c\n", get(list, r)->elem);
			break;
		case 'P':
			print(list); break;
		}
	}

	return 0;
}

*/