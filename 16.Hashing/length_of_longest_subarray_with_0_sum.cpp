#include <bits/stdc++.h>
using namespace std;

int longestSubarray0Sum(int arr[], int n) {
	unordered_map<int, int> m;
	int pre = 0;
	int len = 0;

	for (int i = 0; i < n; i++) {
		pre += arr[i];

		if (pre == 0) {
			len = max(len, i + 1);
		}
		else if (m.find(pre) != m.end()) {
			len = max(len, i - m[pre]);
		}
		else {
			//store the first occurence
			m[pre] = i;
		}
	}
	return len;
}

int main() {

	int n;
	cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		arr[i] = d;
	}

	cout << longestSubarray0Sum(arr, n) << endl;

	return 0;
}