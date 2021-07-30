#include <bits/stdc++.h>
using namespace std;

bool subsetSum_zero(int *arr, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n ; j++)
		{
			int sum = 0;
			for (int k = i; k <= j; k++)
			{	
				sum += arr[k];
				if (sum == 0) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		if (subsetSum_zero(arr, n)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}