#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n) {
	//one iteration = one element sorted
	for (int itr = 1; itr < n; itr++)
	{
		//pairwaise swapping for unsorted part of the array
		for (int j = 0; j <= ((n - 1) - itr); j++) {
			if (a[j] > a[j + 1]) {
				swap (a[j], a[j + 1]);
			}
		}
	}
}

int main() {
	int n, key;
	cin >> n;

	int a[1000];

	for ( int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bubble_sort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}