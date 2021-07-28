#include <bits/stdc++.h>
using namespace std;

#define ll long long

//naive approach O(N)
bool isPrime(int n) {
	if (n == 1) {
		return false;
	}
	if (n == 2) {
		return true;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

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
	int n;
	cin >> n;

	int p[100005] = {0};
	prime_sieve(p);

	//print
	for (int i = 0; i <= n; i++)
	{
		if (p[i] == 1) {
			cout << i << " ";
		}
	}
	/*if (isPrime(n))
	{
		cout << "Yes, It is a prime no." << endl;
	}
	else {
		cout << "No, It isn't a prime no." << endl;
	}*/

	return 0;
}