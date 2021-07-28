#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	//GCD(a,b) = GCD(b, a % b) i.e. recursive
	//GCD (a,0) = a ; we have to run the algo until one become zero(0)
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << "GCD: " <<gcd(a, b) << endl;
	cout << "LCM: " << a*b/gcd(a,b) << endl; 	//gcd * lcm = a * b
	return 0;
}