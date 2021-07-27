#include<bits/stdc++.h>
using namespace std;
/*
Example -
input - N = 10000000000,
M = 10101, i = 2; j = 6
Output = 10001010100
*/
int clearRangeItoJ(int n, int i, int j) {
	int a = (~0) << (j + 1);	//left part 1's
	int b = (1 << i) -  1;	//right part 1's 	//(2^i)-1
	int mask = a | b;
	return n & mask;
}

int replaceBits(int n, int m, int i, int j) {
	int n_ = clearRangeItoJ(n, i, j);
	int ans = (n_) | (m << i);
	return ans;
}

int main() {

	int n = 15;
	int i = 1;
	int j = 3;
	int m = 2;

	cout << replaceBits(n, m, i, j) << endl; 
	return 0;
}