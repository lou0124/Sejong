//시간 측정

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int main()
{
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	int max = 0, n, i, j, * a, * b, temp, ind;

	scanf("%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0;i < n;i++)
	{
		a[i] = rand();
		b[i] = a[i];
	}
	
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = n - 1;i >= 0;i--)
	{
		for (j = i;j >= 0;j--)
		{
			if (a[j] > max) {
				max = a[j];
				ind = j;
			}
		}
		temp = a[ind];
		a[ind] = a[i];
		a[i] = temp;
		max = 0;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fs\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart);
	
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = 1;i < n;i++)
	{
		ind = i;
		temp = b[i];
		for (j = i - 1;j >= 0;j--)
		{
			if (temp < b[j])
			{
				ind--;
				b[j + 1] = b[j];
			}
			else break;
		}
		b[ind] = temp;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fs\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart);




	for (i = n - 1;i >= 0;i--)
	{
		for (j = i;j >= 0;j--)
		{
			if (a[j] > max) {
				max = a[j];
				ind = j;
			}
		}
		temp = a[ind];
		a[ind] = a[i];
		a[i] = temp;
		max = 0;
	}

	for (i = 0;i < n;i++)
	{
		b[i] = a[i];
	}


	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = n - 1;i >= 0;i--)
	{
		for (j = i;j >= 0;j--)
		{
			if (a[j] > max) {
				max = a[j];
				ind = j;
			}
		}
		temp = a[ind];
		a[ind] = a[i];
		a[i] = temp;
		max = 0;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fs\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart);

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = 1;i < n;i++)
	{
		ind = i;
		for (j = i - 1;j >= 0;j--)
		{
			if (b[i] < b[j])
				ind--;
			else break;
		}
		temp = b[i];
		for (j = i; j > ind;j--)
		{
			b[j] = b[j - 1];
		}
		b[ind] = temp;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fs\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart);

	max = 10000000;

	for (i = n - 1;i >= 0;i--)
	{
		for (j = i;j >= 0;j--)
		{
			if (a[j] < max) {
				max = a[j];
				ind = j;
			}
		}
		temp = a[ind];
		a[ind] = a[i];
		a[i] = temp;
		max = 1000000;
	}

	for (i = 0;i < n;i++)
	{
		b[i] = a[i];
	}


	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = n - 1;i >= 0;i--)
	{
		for (j = i;j >= 0;j--)
		{
			if (a[j] > max) {
				max = a[j];
				ind = j;
			}
		}
		temp = a[ind];
		a[ind] = a[i];
		a[i] = temp;
		max = 0;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fs\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart);

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = 1;i < n;i++)
	{
		ind = i;
		temp = b[i];
		for (j = i - 1;j >= 0;j--)
		{
			if (temp < b[j])
			{
				ind--;
				b[j + 1] = b[j];
			}
			else break;
		}
		b[ind] = temp;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fs\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart);

	return 0;
}*/