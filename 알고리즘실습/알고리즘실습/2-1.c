//선택정렬

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max = 0, n, i, j, * arr, temp, ind;

	scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);

	for (i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	for (i = n - 1;i >= 0;i--)
	{
		for (j = i;j >= 0;j--)
		{
			if (arr[j] > max) {
				max = arr[j];
				ind = j;
			}
		}
		temp = arr[ind];
		arr[ind] = arr[i];
		arr[i] = temp;
		max = 0;
	}

	for (i = 0;i < n;i++)
		printf(" %d", arr[i]);

	return 0;
}*/