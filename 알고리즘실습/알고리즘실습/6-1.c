//ÀÌÁø Å½»ö Àç±Í

/*#include <stdio.h>
#include <stdlib.h>


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
	int mid = (l + r) / 2;

	if (k < arr[0]) return -1;

	if (l > r) 
	{
		while (arr[mid] > k ) mid--;
		return mid;
	}

	if (k == arr[mid]) return mid;

	else if (k < arr[mid]) return binarySearch(arr, k, l, mid - 1);

	else return binarySearch(arr, k, mid + 1, r);

}


int main()
{
	int n, k, i, * arr;
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








/*int binarySearch(int* arr, int k, int l, int r)
{
	int mid = (l + r) / 2;
	int gapL, gapM, gapR;

	if (l == r || k == arr[mid]) {
		if (k != arr[mid])
		{
			if (mid == 0)
			{
				gapM = (arr[mid] - k) * (arr[mid] - k);
				gapR = (arr[mid + 1] - k) * (arr[mid + 1] - k);
				if (gapM < gapR) return mid;
				else return mid + 1;
			}
			else if (mid == n - 1)
			{
				gapM = (arr[mid] - k) * (arr[mid] - k);
				gapL = (arr[mid - 1] - k) * (arr[mid - 1] - k);
				if (gapM < gapL) return mid;
				else return mid - 1;
			}
			else
			{
				gapM = (arr[mid] - k) * (arr[mid] - k);
				gapR = (arr[mid + 1] - k) * (arr[mid + 1] - k);
				gapL = (arr[mid - 1] - k) * (arr[mid - 1] - k);
				if (gapR < gapL)
				{
					if (gapM < gapR) return mid;
					else return mid + 1;
				}
				else
				{
					if (gapM < gapL) return mid;
					else return mid - 1;
				}
			}
		}
		return mid;
	}

	else if (k < arr[mid])
		binarySearch(arr, k, l, mid - 1);

	else
		binarySearch(arr, k, mid + 1, r);

}*/