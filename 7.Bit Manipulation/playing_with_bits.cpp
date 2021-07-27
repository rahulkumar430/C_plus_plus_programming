#include<bits/stdc++.h>
using namespace std;
//first method
int countBits(int n) {
	int ans = 0;
	while (n > 0) {
		ans += (n & 1);
		n = n >> 1;
	}
	return ans;
}

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = a; i <= b; i++) {
			ans += countBits(i);
		}
		cout << ans << endl;
	}
	return 0;
}