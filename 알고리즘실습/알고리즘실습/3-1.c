//»ðÀÔ½Ä Èü»ý¼º

/*#include <stdio.h>
#include <stdlib.h>

void upHeap(int);
void downHeap(int);

int H[100], n = 0;

void insertItem(int key)
{
	H[++n] = key;
	upHeap(n);
	printf("0\n");
	return;
}

int removeMax()
{
	int key;
	key = H[1];
	H[1] = H[n--];
	downHeap(1);
	return key;
}

void upHeap(int i)
{
	int temp;

	if (i == 1 || H[i] <= H[i / 2]) return;

	else if (H[i] > H[i / 2])
	{
		temp = H[i / 2];
		H[i / 2] = H[i];
		H[i] = temp;
		upHeap(i / 2);
	}
}

void downHeap(int i)
{
	int temp;

	if (i > n / 2|| (H[i] > H[i * 2] && H[i] > H[i * 2 + 1])) return;

	else if (H[i] < H[i * 2] || H[i] < H[i * 2 + 1])
	{
		if (H[i * 2] > H[i * 2 + 1])
		{
			temp = H[i * 2];
			H[i * 2] = H[i];
			H[i] = temp;
			downHeap(i * 2);
		}
		else
		{
			temp = H[i * 2 + 1];
			H[i * 2 + 1] = H[i];
			H[i] = temp;
			downHeap(i * 2 + 1);
		}
	}
}

void printHeap()
{
	int i;
	for (i = 1;i <= n;i++)
		printf(" %d", H[i]);
	printf("\n");

	return;
}

int main()
{
	int key;
	char ins;

	while (1)
	{
		scanf("%c", &ins);
		switch (ins)
		{
		case 'i':
			scanf("%d", &key); insertItem(key);
			break;
		case 'd':
			printf("%d\n", removeMax());
			break;
		case 'p':
			printHeap();
			break;
		case 'q':
			return 0;
		}
	}
	return 0;
}*/