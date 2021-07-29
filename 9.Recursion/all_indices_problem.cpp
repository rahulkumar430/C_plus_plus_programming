#include <bits/stdc++.h>
using namespace std;

void allOcc(int *a, int i, int n, int key) {
	if (i == n)
		return;
	if (a[i] == key) {
		cout << i << " ";
	}
	allOcc(a, i + 1, n, key);
}

int main() {
	int n;
	cin >> n;

	int arr[10005];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int key;
	cin >> key;
	allOcc(arr, 0, n, key);
	return 0;
}