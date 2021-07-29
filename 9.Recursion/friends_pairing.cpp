#include <bits/stdc++.h>
using namespace std;
/*
#Friends apairing problem
Given n, friends who want to go to a party on bikes. Each guy can go as as single
or as a couple, Find the number of ways in which n friends can go to the party. 

n = 3
ways = 4
*/
int f(int n) {
	if (n == 0 or n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else {
		return f(n - 1) + (n - 1) * f(n - 2);
	}
}

int main() {
	int n;
	cin >> n;

	cout << f(n) << endl;

	return 0;
}