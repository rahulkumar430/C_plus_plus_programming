#include<bits/stdc++.h>
using namespace std;

int first_occurrence(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (a[mid] == key)
		{
			ans = mid;
			e = mid - 1;		//we have to explore the left part
		}
		else if (a[mid] > key)
		{
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int last_occurrence(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (a[mid] == key)
		{
			ans = mid;
			s = mid + 1;		//we have to explore the right part
		}
		else if (a[mid] > key)
		{
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int binary_search(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (a[mid] == key)
		{
			return mid;
		}
		else if (a[mid] > key)
		{
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return -1;
}

int main() {
	int n, key;
	cin >> n;

	int a[1000];

	for ( int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Enter the element that you wanna search :";
	cin >> key;

	//cout << binary_search(a, n, key) << endl;

	cout << first_occurrence(a, n, key) << endl;

	cout << last_occurrence(a, n, key) << endl;	

	return 0;
}