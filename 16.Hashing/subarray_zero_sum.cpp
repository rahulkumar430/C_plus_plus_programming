#include <bits/stdc++.h>
using namespace std;

bool checkSum(int arr[], int n) {

	unordered_set<int> s;
	int pre = 0;
	for (int i = 0; i < n; i++) {
		pre += arr[i];
		//check if the sum was already present in the set
		if (pre == 0 or s.find(pre) != s.end()) {
			return true;
		}
		s.insert(pre);
	}
	return false;
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

	cout << checkSum(arr, n) << endl;

	return 0;
}