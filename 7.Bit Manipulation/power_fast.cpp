#include<bits/stdc++.h>
using namespace std;
//exponentiation
int power_optimised(int a , int n) {
	int ans = 1;
	while (n > 0) {
		int last_bit = (n & 1);
		if (last_bit) {
			ans = ans * a;
		}
		a = a * a;
		n = n >> 1;
	}
	return ans;
}

int main() {

	int a, n;
	cin >> a >> n;

	cout << a << "^" << n << ": " << power_optimised(a, n) << endl;

	return 0;
}