#include <bits/stdc++.h>
using namespace std;

int palindrome(int a[], int start, int end) {
	if (start >= end) {
		return 1;
	}
	if (a[start] == a[end]) {
		return palindrome(a, start + 1, end - 1);
	}
	else {
		return 0;
	}
}

int main() {
	int N;
	cin >> N;

	int a[N] = {0};

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	if (palindrome(a, 0, N - 1) == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}