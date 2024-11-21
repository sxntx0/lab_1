#include "Header.h"

void bub_sort(int A[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
		}
	}
}