#include "Header.h"

void ins_sort(int A[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int j = i, tmp = A[i];

		while (tmp < A[j - 1] && j > 0)
		{
			A[j--] = A[j - 1];
		}
		A[j] = tmp;
	}
}