//俺规 林家过
/*
#include <stdio.h>
#include <stdlib.h>

void insertKey(int * hashTable, int key, int M)
{
	int bucket = key % M;
	
	while (hashTable[bucket % M] != 0)
	{
		printf("C");
		bucket++;
	}
	hashTable[bucket % M] = key;
	printf("%d\n", bucket % M);
}

void searchKey(int* hashTable, int key, int M)
{
	int lastInd = key % M;
	int bucket = key % M;

	while (hashTable[bucket % M] != key) 
	{
		bucket++;
		if (bucket % M == lastInd)
		{
			printf("-1\n");
			return;
		}
	}
	printf("%d %d\n", bucket % M, hashTable[bucket % M]);
}

int main()
{
	int *hashTable, i = 0, M, N, key, bucket;
	char ins;
	scanf("%d %d", &M, &N);

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
			insertKey(hashTable, key, M);
			i++;
			break;
		case 's':
			scanf("%d", &key);
			searchKey(hashTable, key, M);
			break;
		case 'e':
			return 0;
		}
	}
	return 0;
}
*/