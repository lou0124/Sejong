//이진탐색 비재귀

/*#include <stdio.h>
#include <stdlib.h>

int n;

void insertSort(int* arr, int n)
{
	int i, j, temp, ind;

	for (i = 1;i < n;i++)
	{
		ind = i;
		temp = arr[i];
		for (j = i - 1;j >= 0;j--)
		{
			if (temp < arr[j])
			{
				ind--;
				arr[j + 1] = arr[j];
			}
			else break;
		}
		arr[ind] = temp;
	}
}

int binarySearch(int* arr, int k, int l, int r)
{
	int mid; 

	while (l <= r)
	{
		mid = (l + r) / 2;
		if (k == arr[mid]) return mid;
		else if (k < arr[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}

	if (l > r) {
		while (arr[mid] < k && mid < n) mid++; // n 추가필수
		return mid;
	}

}


int main()
{
	int k, i, * arr;
	scanf("%d %d", &n, &k);

	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}

	insertSort(arr, n);
	printf(" %d", binarySearch(arr, k, 0, n - 1));

	free(arr);

	return 0;
}
*/