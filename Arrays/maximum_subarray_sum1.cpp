#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;

	int a[1000];
	int cumSum[1000]={0};
	int maxSum = INT_MIN;
	int currentSum = 0;

	int left = -1;
	int right = -1;

	cin >> a[0];
	cumSum[0] = a[0];

	for (int i = 1; i < n; i++) {
		cin >> a[i];
		cumSum[i] = cumSum[i - 1] + a[i];
	}

//generate all the subarrays
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n ; j++)
		{
			currentSum = 0;

			currentSum = cumSum[j] - cumSum[i - 1];

			if (currentSum > maxSum) {
				maxSum = currentSum;
				left = i; right = j;
			}
		}
	}
	cout << "Maximum subarray sum is :" << maxSum << endl;
	cout << " subarray position: " << left << " to " << right << endl;
	for (int k = left; k <= right; k++)
	{
		cout << a[k] << " ";
	}
	return 0;
}