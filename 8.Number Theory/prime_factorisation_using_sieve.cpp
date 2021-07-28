#include <bits/stdc++.h>
using namespace std;

vector <int> prime_sieve(int *p, int n) {
	//special cases
	p[0] = p[1] = 0;
	p[2] = 1;
	//first maek all the odd no's as prime
	for (int i = 3; i <= n; i += 2) {
		p[i] = 1;
	}
	//sieve
	for (int i = 3; i <= n; i += 2) {
		//if the current number
		if (p[i] == 1)
		{
			// mark all the multiples of i as not prime
			for (int j = i * i; j < n; j = j + i) {
				p[j] = 0;
			}
		}
	}
	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; i <= n; i += 2)
	{
		if (p[i] == 1) {
			primes.push_back(i);
		}
	}
	return primes;
}

vector<int> factorize(int m, vector<int> &primes) {
	vector<int> factors;
	factors.clear();

	int i = 0;
	int p = primes[0];

	while (p * p <= m) {
		if (m % p == 0) {
			factors.push_back(p);
			//cout <<"p value:" << p << endl;
			while (m % p == 0) {
				//cout <<"p value:" << p << endl;
				m = m / p;
				//cout << "m value:" <<m << endl;
			}
		}
		//go to the next position
		i++;
		p = primes[i];
		//cout <<"p value:" << p << endl;
	}
	if (m != 1) {
		factors.push_back(m);
	}
	return factors;
}

int main() {
	int p[100005] = {0};
	vector<int> primes = prime_sieve(p, 1000);
	int tc;
	cin >> tc;
	while (tc--) {
		int no;
		cin >> no;
		vector <int> factors = factorize(no, primes);
		for (auto f : factors) {
			cout << f << " " << endl;
		}
	}
	return 0;
}