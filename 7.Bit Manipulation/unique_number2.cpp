#include <bits/stdc++.h>
using namespace std;

int main() {
	//Unique number 2N + 2
	//Given a list of numbers where every numbers occurs twice except two, find it
	//Have to do it in linear space
	int n;
	int a[100005];
	cin >> n;
	int no;
	int res = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> no;
		a[i] = no;
		res = res ^ no;
	}

	int temp = res;
	int pos = 0;

	while ((temp & 1) != 1) {
		pos++;
		temp = temp >> 1;
	}

	//the first set bit is at position "pos"
	int mask = (1 << pos);
	int ans1 = 0;
	int ans2 = 0;
	//find those numbers which contain set bit at position'pos'
	for (int i = 0; i < n; i++)
	{
		if ((a[i] & mask) > 0) {
			ans1 = ans1 ^ a[i];
		}
	}
	ans2 = res ^ ans1;

	cout << min(ans1, ans2) << " " << max(ans1, ans2) << endl;
	return 0;
}