#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {
	int t;
	cin >> t;
    int n, b;
	int a[N] ;
	int tc = 0;
	while (t--) {
		tc++;
		cin >> n >> b;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (b >= a[i]) {
				ans++;
				b -= a[i];
			}
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}