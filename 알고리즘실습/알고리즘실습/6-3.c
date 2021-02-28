// 이진탐색 응용

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findAnswer(int A, int B, int ind, char *yn)
{
	int M = (A + B) / 2;
	if (yn[ind] == NULL) return M;

	else if (yn[ind] == 'Y') return findAnswer(M + 1, B, ind + 1, yn);
	else return findAnswer(A, M, ind + 1, yn);
}

int main()
{
	int A, B, num, i;
	char *yn;
	
	scanf("%d %d %d", &A, &B, &num);

	yn = (char*)malloc(sizeof(char) * num + 1);

	scanf("%s", yn);

	printf("%d", findAnswer(A, B, 0, yn));

	return 0;
}*/