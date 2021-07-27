#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n) {
	return (n & 1);
}

int getBit(int &n , int i) {
	int mask = (1 << i);
	int bit = (n & mask) > 0 ? 1 : 0;
	return  bit ;
}

int setBit(int &n , int i) {
	int mask = (1 << i);
	int ans = n | mask;
	return ans;
}

void clearBit(int &n , int i) {
	int mask = ~(1 << i);
	n = n & mask;
}

void updateBit(int &n , int i, int v) {
	int mask = ~(1 << i);
	int v_pos = (v << i);
	n = (n & mask) | v_pos ;
}

int clearLastBits(int n, int i) {
	int mask = (-1 << i);
	return n & mask;
}

int clearRangeItoJ(int n, int i, int j) {
	int a = (~0) << (j + 1);	//left part 1's
	int b = (1 << i) -  1;	//right part 1's 	//(2^i)-1
	int mask = a | b;
	return n & mask;
}

int main() {

	int n = 31;
	int i = 1;	//from position i+1 to 0 i.e. if i = 3 then it'll clear last 2 bits
	int j = 3;
	/*cout << isOdd(n) << endl;
	cout << getBit(n, i) << endl;
	cout << setBit(n, i) << endl;

	clearBit(n, i);
	cout << n << endl;
	int v;
	cin >> v;
	updateBit(n, i, v);
	cout << n << endl;*/

	// cout << clearLastBits(n, i) << endl;
	cout << clearRangeItoJ(n, i, j) << endl;
	return 0;
}