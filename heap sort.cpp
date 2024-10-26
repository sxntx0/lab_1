#include "Header.h"

void heapify(int A[], int n, int i) {
    int largest = i;
    int r = 2 * i + 2;
    int l = 2 * i + 1;
    if (l < n && A[l] > A[largest]) largest = l;
    if (r < n && A[r] > A[largest]) largest = r;
    if (largest != i)
    {
        swap(A[largest], A[i]);
        heapify(A, n, largest);
    }
}

void hep_sort(int A[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--) heapify(A, len , i);
    for (int i = len - 1; i >= 0; i--) { swap(A[0], A[i]); heapify(A, i, 0); }
}