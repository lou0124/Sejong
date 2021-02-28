//»ğÀÔÁ¤·Ä

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max = 0, ind, n, i, j, * arr, temp;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0;i < n;i++)
		scanf("%d", &arr[i]);

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

	for (i = 0;i < n;i++)
		printf(" %d", arr[i]);

	return 0;
}
*/
