#include<bits/stdc++.h>
using namespace std;
//first method
int countBits(int n) {
	int ans = 0;
	while (n > 0) {
		ans += (n & 1);
		n = n >> 1;
	}
	return ans;
}

//second method	
int countBitsFast(int n) {
	int ans = 0;
	while (n > 0) {
		n = n & (n - 1);	//delete set bits from right to left
		ans++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	cout << countBits(n) << endl;
	cout << countBitsFast(n) << endl;
	//third method
	cout<<__builtin_popcount(n)<<endl;
	return 0;
}