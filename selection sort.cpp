#include "Header.h"

void sel_sort(int A[], int len)
{
	int min, tmp;
	for (int i = 0; i < len; i++)
	{
		min = i;
		for (int j = i; j < len; j++)
		{
			if (A[min] > A[j])
			{
				min = j;
			}
		}
		tmp = A[i]; A[i] = A[min]; A[min] = tmp;
	}
}