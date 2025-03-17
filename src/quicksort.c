#include "quicksort.h"

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			swap(&A[i], &A[j]);
		}
	}

	return (i < r)? i: i - 1;
}

void quicksort(int *A, int lo, int hi)
{
	if (lo >= hi || lo < 0)
	{
		return;
	}

	int p = partition(A, lo, hi);
	quicksort(A, lo, p);
	quicksort(A, p + 1, hi);
}
