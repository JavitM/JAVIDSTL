// JAVIDSTL. Created By Javid Mamedov.
#pragma once
#include "array.h"
#include "vector.h"
#include "core.h"

template<int S>
void SelectionSort(JAVIDSTL::Array<int,S>& A)
{
	for (int i = 0; i < S - 1; i++)
	{
		int minindex = i;

		for (int j = i; j < S; j++)
		{
			if (A[j] < A[minindex])
			{
				minindex = j;
			}
		}

		int temp = A[i];
		A[i] = A[minindex];
		A[minindex] = temp;

	}
}

void SelectionSort(int A[], int S)
{
	for (int i = 0; i < S - 1; i++)
	{
		int minindex = i;

		for (int j = i; j < S; j++)
		{
			if (A[j] < A[minindex])
			{
				minindex = j;
			}
		}

		int temp = A[i];
		A[i] = A[minindex];
		A[minindex] = temp;
	}
}

template<int S>
void BubbleSort(JAVIDSTL::Array<int, S>& A)
{
	for (int i = 1; i < S - 1; i++) 
	{
		int madesort = false;
		for (int j = 0; j < (S - i); j++)
		{
			if (A[j] > A[j + 1])
			{
				int temp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = temp;
				madesort = true;
			}
		}
		if (!madesort)
		{
			break;
		}
	}
}

void BubbleSort(int A[], int S)
{
	for (int i = 1; i < S - 1; i++)
	{
		int madesort = false;
		for (int j = 0; j < (S - i); j++)
		{
			if (A[j] > A[j + 1])
			{
				JAVIDSTL::Utilities::Swap<int>(A[j], A[j + 1]);
				madesort = true;
			}
		}
		if (!madesort)
		{
			break;
		}
	}
}

template<int S>
void InsertionSort(JAVIDSTL::Array<int, S>& A)
{
	for (int i = 1; i < S; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (j == i - 1 && !(A[j] > A[i]))
			{
				break;
			}

			if (A[j] > A[i])
			{
				int value = A[j];
				A[j] = A[i];
				A[i] = value;
				i--;
			}
		}
	}
}

void InsertionSort(int A[], int S)
{
	for (int i = 1; i < S; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (j == i - 1 && !(A[j] > A[i]))
			{
				break;
			}

			if (A[j] > A[i])
			{
				int value = A[j];
				A[j] = A[i];
				A[i] = value;
				i--;
		    }
		}
	}
}

template<size_t S, size_t S1, size_t S2>
void Merge(JAVIDSTL::Array<int, S1>& left, JAVIDSTL::Array<int, S2>& right, JAVIDSTL::Array<int, S>& A)
{
	int nleft = left.Size();
	int nright = right.Size();
	int i = 0; int j = 0; int k = 0;

	while (i < nleft && j < nright)
	{
		if (left[i] <= right[j])
		{
			A[k] = left[i];
			i++;
		}
		else
		{
			A[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < nleft)
	{
		A[k] = left[i];
		i++;
		k++;
	}

	while (j < nright)
	{
		A[k] = right[j];
		j++;
		k++;
	}
}

template<size_t S>
void MergeSort(JAVIDSTL::Array<int, S>& A)
{
	if (S < 2) { return; }

	constexpr size_t mid = S / 2;

	JAVIDSTL::Array<int, mid> left;
	JAVIDSTL::Array<int, S - mid> right;

	for (int i = 0; i < mid; i++) 
	{ 
		left[i] = A[i]; 
	}
	int j = 0;
	for (int i = mid; i < S; i++) 
	{ 
		right[j] = A[i]; 
		j++;
	}

	MergeSort<mid>(left);
	MergeSort<S - mid>(right);
	Merge(left, right, A);
}

template<size_t S>
int Partition(JAVIDSTL::Array<int, S>& A, int startIndex, int endIndex)
{
	int Pivot = A[endIndex];
	int pIndex = startIndex;
	for (int i = startIndex; i < endIndex; i++)
	{
		if (A[i] <= Pivot)
		{
			//JAVIDSTL::Utilities::Swap<int>(&A[i], &A[pIndex]);
			//swap(&A[i], &A[pIndex]);
			int temp = A[i];
			int temp1 = A[pIndex];
			A[i] = temp1;
			A[pIndex] = temp;
			pIndex += 1;
		}
	}
	//JAVIDSTL::Utilities::Swap<int>(&A[pIndex], &A[endIndex]);
	int temp = A[pIndex];
	int temp1 = A[endIndex];
	A[pIndex] = temp1;
	A[endIndex] = temp;
	//pIndex += 1;
	return pIndex;
}

template<size_t S>
void QuickSort(JAVIDSTL::Array<int, S>& A, int startIndex, int endIndex)
{
	if (startIndex >= endIndex) { return; }
	int pIndex = Partition(A, startIndex, endIndex);
	QuickSort<S>(A, startIndex, pIndex - 1);
	QuickSort<S>(A, pIndex + 1, endIndex);
}
