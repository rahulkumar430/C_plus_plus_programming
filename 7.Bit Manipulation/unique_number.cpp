#include<bits/stdc++.h>
using namespace std;

int main() {
	//Unique number 2N + 1
	//Given a list of numbers where every numbers occurs twice except one, find it
	int n;
	cin >> n;

	int no;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> no;
		ans = ans ^ no;	//Bitwise operator XOR to solve 
		// n ^ n = 0; &  n ^ n ^ m = m
	}

	cout << ans << endl;

	return 0;
}