#include <bits/stdc++.h>
using namespace std;

int power(int a, int n) {
	if (n == 0)
		return 1;
	return a * power(a, n - 1);
}

int fast_power(int a, int n) {
	if (n == 0)
		return 1;
	int smaller_ans = fast_power(a, n / 2);
	smaller_ans *= smaller_ans;
	if (n % 2 == 0)
		return smaller_ans; // don't write fast_power(a, n / 2)* fast_power(a, n / 2) cause the system will take double time to repeat the same
	else
		return smaller_ans * a;
}

int main() {
	int a, n;
	cin >> a >> n;

	cout << power(a, n) << endl;
	cout << fast_power(a, n) << endl;

	return 0;
}