#include <bits/stdc++.h>
using namespace std;

#define ll long long

//Sieve approach - generate an array containing prime numbers
void prime_sieve(int *p) {
	//first maek all the odd no's as prime
	for (ll i = 3; i <= 100000; i += 2) {
		p[i] = 1;
	}
	//sieve
	for (ll i = 3; i <= 100000; i += 2) {
		//if the current number
		if (p[i] == 1)
		{
			// mark all the multiples of i as not prime
			for (ll j = i * i; j < 100000; j = j + i) {
				p[j] = 0;
			}
		}
	}
	//special cases
	p[2] = 1;
	p[1] = p[0] = 0;
}

int main() {
	int tc;
	cin >> tc;

	int p[100005] = {0};
	prime_sieve(p);

	int csum[100005] = {0};
	//precompute the primes upto an index i
	for (int i = 1; i < 100000; i++)
	{
		csum[i] = csum[i - 1] + p[i];
	}

	while (tc--) {
		int a, b;
		cin >> a >> b;

		cout << csum[b] - csum[a - 1] << endl;
	}

	return 0;
}