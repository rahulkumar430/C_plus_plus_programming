/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int s, int e)
{
	int pivot = arr[e]; // pivot
	int i = (s - 1); // Index of smaller element

	for (int j = s; j <= e - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[e]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
s --> Starting index,
e --> Ending index */
void quickSort(int arr[], int s, int e)
{
	if (s < e)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int p = partition(arr, s, e);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, s, p - 1);
		quickSort(arr, p + 1, e);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	int arr[] = {1, 8, 9, 3, 4, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printArray(arr, n);
	return 0;
}
