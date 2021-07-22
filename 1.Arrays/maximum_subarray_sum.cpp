#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;

	int a[1000];
	int maxSum = INT_MIN;
	int currentSum = 0;
	int left = -1;
	int right = -1;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

//generate all the subarrays
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n ; j++)
		{
			currentSum = 0;
			//elements of subarray(i,j)
			for (int k = i; k <= j; k++)
			{
				currentSum += a[k];
			}
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