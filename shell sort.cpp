#include "Header.h"

int shell_d(int d)
{
	return d / 2;
}

int hibbr_d(int d)
{
	int n = 1;
	while (n << 1 < d + 1) n <<= 1;
	return n - 1;
}

int pratt_d(int d)
{
	if (d > 1)
	{
		int n = 1;
		while (pow(2, n) * pow(3, n) <= d >> 1) n++;
		return pow(2, n - 1) * pow(3, n - 1);
	}
	return 0;
}

int set_d(int d)
{
	//return shell_d(d);
	//return hibbr_d(d);
	return pratt_d(d);
}

//void shl_sort_h(int A[], int d, int len)
//{
//	if (d > 0)
//	{
//		int tmp, v;
//		for (int u = d; u < len; u += d)
//		{
//			v = u, tmp = A[u];
//			while (tmp < A[v - d] && v - d >= 0)
//			{
//				A[v] = A[v - d];
//				v -= d;
//			}
//			A[v] = tmp;
//		}
//		shl_sort_h(A, set_d(d), len);
//	}
//}
void shl_sort(int A[], int len)
{
	int d = set_d(len);
	int tmp, v;
	while (d > 0) 
	{
		for (int u = d; u < len; u+=d) 
		{
			tmp = A[u];
			v = u;
			while (v - d >= 0 && tmp < A[v - d])
			{
				A[v] = A[v - d];
				v -= d;
			}
			A[v] = tmp;
		}
		d = set_d(d);
	}
}

//void shl_sort(int A[], int len)
//{
//	shl_sort_h(A, len);
//	out_data(A, len); cout << endl;
//}