#include <bits/stdc++.h>
using namespace std;

/*
Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m .
A tile can either be placed horizontally or vertically.
\
Print answer for every test case in a new line modulo 10^9+7.
*/
#define ll long long
long long int mod = 1000000007;

ll placetile(ll n, ll m) {
	//base case
	if (n == 0) {
		return 0;
	}
	else if (n < m) {
		return 1;
	}
	else if (n == m) {
		return 2;
	}
	else {
		return (placetile(n - 1, m) + placetile(n - m, m))% mod;
	}

}

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		ll n, m;
		cin >> n >> m ;

		cout << placetile(n, m) << endl;
	}
	return 0;
}