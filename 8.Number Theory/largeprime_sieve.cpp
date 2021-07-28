#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

//Sieve approach - generate an array containing prime numbers
void prime_sieve() {

	b.set(); // set all bits -> 1,1,1,1,.....
	//https://www.geeksforgeeks.org/bitset-set-function-in-c-stl/
	b[1] = b[0] = 0;
	//sieve
	for (ll i = 2; i <= n; i ++) {
		if (b[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j <= n; j = j + i) {
				b[j] = 0;
			}
		}
	}
}

bool isPrime(ll no) {
	if (no <= n) {
		return b[no] == 1 ? true : false;
	}

	for (ll i = 0; primes[i] * (ll)primes[i] <= no; i++)
	{
		if (no % primes[i] == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	ll n;
	cin >> n;
	prime_sieve();

	if (isPrime(n)) {
		cout << "Yes it is a prime number." << endl;
	}
	else {
		cout << "No it isn't a prime number." << endl;
	}
	return 0;
}