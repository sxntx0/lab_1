#include "Header.h"

void bub_sort(int A[], int len)
{
	bool ok; int i, tmp;
	do
	{
		i = 0; ok = false;
		while (i < len - 1)
		{
			if (A[i] > A[i + 1])
			{
				tmp = A[i]; ok = true;
				A[i] = A[i + 1]; A[i + 1] = tmp;
			}
			i++;
		}
	} while (ok);
}