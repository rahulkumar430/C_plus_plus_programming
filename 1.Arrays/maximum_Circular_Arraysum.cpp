#include<bits/stdc++.h>
using namespace std;

int kadane(int a[], int n) {
	int maxsum = 0;
	int currentsum = 0;

	for (int i = 0; i < n ; i++)
	{
		currentsum = currentsum + a[i];
		if (currentsum < 0) {
			currentsum = 0;
		}
		maxsum = max(currentsum, maxsum);
	}
	return maxsum;
}

int maxCircularSum()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	// Case 1: get the maximum sum using standard kadane'
	// s algorithm
	int max_kadane = kadane(a, n);

	// Case 2: Now find the maximum sum that includes
	// corner elements.
	int max_wrap = 0, i;
	for (i = 0; i < n; i++) {
		max_wrap += a[i]; // Calculate array-sum
		a[i] = -a[i]; // invert the array (change sign)
	}

	// max sum with corner elements will be:
	// array-sum - (-max subarray sum of inverted array)
	max_wrap = max_wrap + kadane(a, n);
	delete [] a;

	// The maximum circular sum will be maximum of two sums
	return (max_wrap > max_kadane) ? max_wrap : max_kadane;
}

int main() {

	int N;
	cin >> N;

	int* array = new int[N];

	for (int i = 0; i < N; i++) {
		array[i] = maxCircularSum();
	}

	for (int i = 0; i < N; i++)
	{
		cout << array[i] << endl;
	}
	delete [] array;

	return 0;
}