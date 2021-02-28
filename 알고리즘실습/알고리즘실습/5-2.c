//ÄüÁ¤·Ä

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inPlaceQuickSort(int *arr, int l, int r);
int inPlacePartition(int* arr, int l, int r, int k);
int find_pivot_index(L, l, r);

int main()
{
	int i, * arr, n;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	srand(time(NULL));

	inPlaceQuickSort(arr, 0, n - 1);

	for (i = 0;i < n;i++)
		printf(" %d", arr[i]);

	return 0;
}


void inPlaceQuickSort(int *arr, int l, int r)
{
	int i, k;
	
	if (l >= r) return;
	
	k = find_pivot_index(arr, l, r);
	i = inPlacePartition(arr, l, r, k);


	inPlaceQuickSort(arr, l, i - 1);
	inPlaceQuickSort(arr, i + 1, r);
}

int find_pivot_index(int *arr, int l, int r)
{
	int ind1, ind2, ind3;
	ind1 = (rand() % (l - r)) + l;
	ind2 = (rand() % (l - r)) + l;
	ind3 = (rand() % (l - r)) + l;

	if ((arr[ind2] >= arr[ind1] && arr[ind1] >= arr[ind3]) || (arr[ind3] >= arr[ind1] && arr[ind1] >= arr[ind2])) return ind1;
	else if ((arr[ind1] >= arr[ind2] && arr[ind2] >= arr[ind3]) || (arr[ind3] >= arr[ind2] && arr[ind2] >= arr[ind1])) return ind2;
	else return ind3;
}

int inPlacePartition(int* arr, int l, int r, int k)
{
	int temp, i, j;
	int p = arr[k];
	temp = arr[k];
	arr[k] = arr[r];
	arr[r] = temp;

	i = l;
	j = r - 1;
	while (i <= j)
	{
		while (i <= j && arr[i] <= p)i++;
		while (j >= i && arr[j] >= p)j--;

		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;

	return i;
}
*/