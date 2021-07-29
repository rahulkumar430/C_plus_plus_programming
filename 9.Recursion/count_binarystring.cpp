#include <bits/stdc++.h>
using namespace std;

/*
# Count binary string
Count binary strings of length N such that it has no consecutive ones.
*/

int f(int n) {
	//base case
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 2;
	}
	else if (n == 2) {
		return 3;
	}
	else {
		return f(n - 1) + f(n - 2);
	}
}

int main() {
	int n;
	cin >> n;

	cout << f(n) << endl;
	return 0;
}