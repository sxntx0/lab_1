#include "Header.h"

void data_copy(int A[], int start, int end, int B[])
{
	for (int i = start; i < end; i++)
	{
		A[i] = B[i];
	}
}

void mrg_sort_h(int A[], int start, int end, int B[])
{
	if (end - start > 1)
	{
		int u = start, u_max = start + (end - start) / 2;
		int v = u_max, v_max = end; int k = start;

		mrg_sort_h(A, u, u_max, B);
		mrg_sort_h(A, v, v_max, B);

		while (u < u_max && v < v_max)
		{
			if (A[u] <= A[v])
			{
				B[k++] = A[u++];
			}
			else
			{
				B[k++] = A[v++];
			}
		}
		while (u < u_max)
		{
			B[k++] = A[u++];
		}
		while (v < v_max)
		{
			B[k++] = A[v++];
		}

		data_copy(A, start, end, B);
	}
}

void mrg_sort(int A[], int len)
{
	int* B = new int [len];
	mrg_sort_h(A, 0, len, B);
	delete[] B;
}