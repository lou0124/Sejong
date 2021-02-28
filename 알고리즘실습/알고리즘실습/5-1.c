//합병 정렬

/*#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node {
	int data;
	struct Node* next;
}Node;


Node* merge(Node* L1, Node* L2);
void mg_partition(Node* temp, Node** L1, Node** L2);
void mergeSort(Node** L);

void mergeSort(Node** L)
{
	Node* temp = *L;
	Node* L1, * L2;

	if (temp == NULL || temp->next == NULL)  return;

	mg_partition(temp, &L1, &L2);

	mergeSort(&L1);
	mergeSort(&L2);

	*L = merge(L1, L2);
}


Node* merge(Node* L1, Node* L2)
{
	Node* result = NULL;

	if (L1 == NULL)	return L2;
	else if (L2 == NULL) return L1;


	if (L1->data < L2->data)
	{
		result = L1;
		result->next = merge(L1->next, L2);
	}
	else
	{
		result = L2;
		result->next = merge(L1, L2->next);
	}
	return result;
}

void mg_partition(Node* temp, Node** L1, Node** L2)
{
	Node* fast, * slow;
	slow = temp;
	fast = temp->next;


	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*L1 = temp;
	*L2 = slow->next;
	slow->next = NULL;
}



void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


void addNode(Node** head, int elem)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	Node* temp;
	newnode->data = elem;
	newnode->next = NULL;

	if (*head == NULL)* head = newnode;

	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}

int main()
{

	Node* L = NULL;
	int n, i, elem;

	scanf("%d", &n);

	for (i = 0;i < n;i++)
	{
		scanf("%d", &elem);
		addNode(&L, elem);
	}


	mergeSort(&L);
	printList(L);

	return 0;
}*/






















/*#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int item;
	struct Node* link;
}Node;


typedef struct headList{
	struct Node* head;
}headList;


headList* createHead();
void addNode(headList* L, int elem);
void mergeSort(headList* L);
void printList(headList* L);
headList* merge(headList* L1, headList* L2);
headList** mg_partition(headList* L, int k);

int n;

int main()
{
	headList* L;
	int i, elem;
	L = createHead();

	scanf("%d", &n);

	for (i = 0;i < n;i++) 
	{
		scanf("%d", &elem);
		addNode(L, elem);
	}

	mergeSort(L);

	return 0;
}


headList* createHead()
{
	headList* H = (headList*)malloc(sizeof(headList));
	H->head = NULL;
	return H;
}


void addNode(headList* L, int elem)
{
	Node* newnode;
	Node* temp;

	newnode = (Node*)malloc(sizeof(Node));
	newnode->item = elem;
	newnode->link = NULL;

	if (L->head == NULL) 
	{
		L->head = newnode;
		return;
	}

	temp = L->head;
	while (temp->link != NULL) temp = temp->link;

	temp->link = newnode;
	
}


void printList(headList* L)
{
	Node* temp = L->head;
	while (temp != NULL)
	{
		printf(" %d", temp->item);
		temp = temp->link;
	}
	printf("\n");
}

void mergeSort(headList* L)
{
	headList** sL;
	headList* mL;
	sL = mg_partition(L, n / 2);
	mL = merge(sL[0], sL[1]);
	printList(mL);
}


headList* merge(headList* L1, headList* L2)
{
	headList* L;
	Node* temp, * temp1, * temp2;

	L = createHead();
	temp = L->head;
	temp1 = L2->head;
	temp2 = L1->head;
	
	while (temp1 != NULL || temp2 != NULL)
	{
		if (temp1->item < temp2->item) 
		{
			temp = temp1;
			temp1 = temp1->link;
			temp = temp->link;
		}
		else
		{
			temp = temp2;
			temp2 = temp2->link;
			temp = temp->link;
		}
	}
	if (temp1 == NULL) temp = temp2;
	else if (temp2 == NULL) temp = temp1;

	return L;
}


headList** mg_partition(headList* L, int k)
{
	Node* temp;
	headList** sL;
	int i;
	sL = (headList * *)malloc(sizeof(headList));
	sL[0] = createHead();
	sL[1] = createHead();
	sL[0]->head = L->head;

	temp = L->head;

	for (i = 1;i < k;i++) temp = temp->link;

	sL[1]->head = temp->link;
	temp->link = NULL;

	printList(sL[0]);
	printList(sL[1]);


	return sL;
}*/

/*
#include <stdio.h>
#include <stdlib.h>


int n;

void merge(int* arr, int l, int m, int r)
{

	int i = l, k = l, j = m + 1, *brr;
	brr = (int*)malloc(sizeof(int) * n);
	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j]) brr[k++] = arr[i++];
		else brr[k++] = arr[j++];
	}

	while (i <= m) brr[k++] = arr[i++];
	while (i <= m) brr[k++] = arr[j++];
	for (k = l;k <= r;k++) arr[k] = brr[k];

	return;
}

void rMergeSort(int* arr, int l, int r)
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2;
		rMergeSort(arr, l, m);
		rMergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
	return;
}



void mergeSort(int* arr)
{
	rMergeSort(arr, 0, n - 1);
	return;
}


int main()
{
	int* arr, i;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0;i < n;i++) scanf("%d", &arr[i]);

	mergeSort(arr);

	for (i = 0;i < n;i++) printf(" %d", arr[i]);

	return 0;
}

*/