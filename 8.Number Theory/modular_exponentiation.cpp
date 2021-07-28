#include <bits/stdc++.h>
using namespace std;

#define ll long long
//https://www.youtube.com/watch?v=8vNZvIoWIwc
ll powM(ll b, ll e, ll mod) {
	if (e == 0)
		return 1;
	ll k = powM(b, e / 2, mod);
	if (e % 2 == 1)
		return ((((k * k) % mod) * b) % mod);
	else
		return ((k * k) % mod);
}

ll modular(ll base, ll exp, ll mod) {
	ll res = 1;
	while (exp > 0) {
		if (exp % 2 == 1)
			res = (res * base) % mod;
		exp = exp >> 1;
		base = (base * base) % mod;
	}
	return res;
}
int main() {
	ll b, e, mod;
	cin >> b >> e >> mod;
	cout << modular(b, e , mod) << endl;
	cout << powM(b, e , mod) << endl;
	return 0;
}

/*Fermat's little thoerom
if m is a prime then,
(x^(m-1))%m = 1 */
