#include<bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selection_sort(int a[], int n) {

	for (int i = 0; i < n - 1; i++)
	{
		/* find out the smallest element ith index in the unsorted part*/
		int min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_index])
			{
				min_index = j;
			}
		}

		swap(&a[i], &a[min_index]);
	}

}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	int n, key;
	cin >> n;

	int a[1000];

	for ( int i = 0; i < n; i++) {
		cin >> a[i];
	}
	selection_sort(a, n);
	printArray(a, n);

	return 0;
}