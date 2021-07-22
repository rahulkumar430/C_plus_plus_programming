#include<bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{

// To store the maximum water
// that can be stored
	int res = 0;

// For every element of the array
	for (int i = 1; i < n - 1; i++) {

		// Find the maximum element on its left
		int left = arr[i];
		for (int j = 0; j < i; j++)
			left = max(left, arr[j]);

		// Find the maximum element on its right
		int right = arr[i];
		for (int j = i + 1; j < n; j++)
			right = max(right, arr[j]);

		// Update the maximum water
		res = res + (min(left, right) - arr[i]);
	}

	return res;
}


	int main() {
		int N;
		cin >> N;
		int a[N] = {0};
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
		}
		cout<<maxWater(a, N);
		return 0;
	}