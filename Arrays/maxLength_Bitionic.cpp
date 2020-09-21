#include<bits/stdc++.h>
using namespace std;

int maxlengthBitonic() {

	int n;
	cin >> n;
	int* a = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
    // Length of increasing subarray
	// ending at all indexes
	int inc[n];

	// Length of decreasing subarray
	// starting at all indexes
	int dec[n];
	int i, max;

	// length of increasing sequence
	// ending at first index is 1
	inc[0] = 1;

	// length of increasing sequence
	// starting at first index is 1
	dec[n - 1] = 1;

	// Step 1) Construct increasing sequence array
	for (i = 1; i < n; i++)
		inc[i] = (a[i] >= a[i - 1]) ? inc[i - 1] + 1 : 1;

	// Step 2) Construct decreasing sequence array
	for (i = n - 2; i >= 0; i--)
		dec[i] = (a[i] >= a[i + 1]) ? dec[i + 1] + 1 : 1;

	// Step 3) Find the length of
	// maximum length bitonic sequence
	max = inc[0] + dec[0] - 1;
	for (i = 1; i < n; i++)
		if (inc[i] + dec[i] - 1 > max)
			max = inc[i] + dec[i] - 1;

	delete [] a;
	return max;
}

int main() {

	int N;
	cin >> N;

	int* array = new int[N];

	for (int i = 0; i < N; i++) {
		array[i] = maxlengthBitonic();
	}

	for (int i = 0; i < N; i++)
	{
		cout << array[i] << endl;
	}
	delete [] array;

	return 0;
}