#include <bits/stdc++.h>
using namespace std;

int l, r, a, b, ret;

int main () {

	cin >> l >> r;
	for (a = l; a <= r; a++) {
		for (b = a; b <= r; b++) {
			ret = max(ret, a ^ b);
		}
	}
	cout << ret << endl;
	return 0;
}