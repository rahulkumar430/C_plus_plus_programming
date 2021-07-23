#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int k, int curr_min) {
	int painterUsed = 1;
	int board = 0;

	for (int i = 0; i < n; i++)
	{
		//cout << board + arr[i] << " "<< curr_min << endl;
		if (board + arr[i] > curr_min) {
			painterUsed++;
			//cout << painterUsed << endl;
			board = arr[i];
			if (painterUsed > k) {
				return false;
			}
		}
		else {
			board += arr[i];
			//cout << board << endl;
		}
	}
	return true;
}

int findTime(int arr[], int n, int k) {
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	int s = arr[n - 1];
	int e = sum;
	int ans = INT_MAX;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (isPossible(arr, n, k, mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {
	int n, k, t;
	//n = board length array, k = no of painters, t = time every painter take
	int arr[n];
	cin >> n >> k >> t;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cout << (findTime(arr, n, k))*t << endl;

	return 0;
}
