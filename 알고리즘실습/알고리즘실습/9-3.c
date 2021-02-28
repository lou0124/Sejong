//俺规 林家过 捞吝秦教

/*#include <stdio.h>
#include <stdlib.h>

void insertKey(int * hashTable, int key, int M, int q)
{
	int bucket = key % M;

	while (hashTable[bucket % M] != 0)
	{
		printf("C");
		bucket += (q - (key % q));
	}
	hashTable[bucket % M] = key;
	printf("%d\n", bucket % M);
}

void searchKey(int* hashTable, int key, int M, int q)
{
	int count = 0;
	int bucket = key % M;

	while (hashTable[bucket % M] != key)
	{
		bucket += q - (key % q);
		count++;
		if (count >= M)
		{
			printf("-1\n");
			return;
		}
	}
	printf("%d %d\n", bucket % M, hashTable[bucket % M]);
}

void printHashtable(int* hashTable, int M)
{
	int i;
	for (i = 0;i < M;i++) 
		printf(" %d", hashTable[i]);
	printf("\n");
}

int main()
{
	int *hashTable, i = 0, M, N, q, key, bucket;
	char ins;
	scanf("%d %d %d", &M, &N, &q);

	hashTable = (int*)calloc(M, sizeof(int));

	while (1)
	{
		scanf("%c", &ins);
		switch (ins)
		{
		case 'i':
			if (i >= N)
				break;
			scanf("%d", &key);
			insertKey(hashTable, key, M, q);
			i++;
			break;
		case 's':
			scanf("%d", &key);
			searchKey(hashTable, key, M, q);
			break;
		case 'p':
			printHashtable(hashTable, M);
			break;
		case 'e':
			printHashtable(hashTable, M);
			return 0;
		}
	}
	return 0;
}
*/