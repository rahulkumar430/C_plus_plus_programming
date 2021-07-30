#include <bits/stdc++.h>
using namespace std;

/*
#place the tiles
Given a wall of size 4*N, and tile sof size (1,4) and (4,1).
In howmany ways you can build the wall ?
*/

int placetile(int n) {
	//base case
	if (n == 0) {
		return 0;
	}
	else if (n < 4) {
		return 1;
	}
	else if (n == 4) {
		return 2;
	}
	else {
		return placetile(n - 1) + placetile(n - 4);
	}

}

int main() {
	int n;
	cin >> n;

	cout << placetile(n) << endl;
	return 0;
}