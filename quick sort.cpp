#include "Header.h"

void qck_sort_h(int A[], int start, int end)
{
	if (end > start)
	{
		int middle = A[(start+end)/ 2];
		int u = start, v = end, tmp;
		while (u < v)
		{
			while (A[u] < middle) u++;
			while (A[v] > middle) v--;

			if (u <= v)
			{
				tmp = A[u];
				A[u++] = A[v];
				A[v--] = tmp;
			}

		}
		qck_sort_h(A, start, v); 
		qck_sort_h(A, u, end);
	}
}

void qck_sort(int A[], int len)
{
	qck_sort_h(A, 0, len - 1);
}