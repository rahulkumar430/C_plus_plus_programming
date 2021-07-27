#include <bits/stdc++.h>
using namespace std;

int main() {
	//Unique number 3N + 1
	//Given a list of numbers where every numbers occurs thrice except one, find it

	int n;
	cin >> n;
	int no;
	int cnt[64] = {0};

	for (int i = 0; i < n; i++)
	{
		cin >> no;
		int j = 0;
		while (no > 0) {
			//update the cnt array by extracting bits
			int last_bit = (no & 1);
			cnt[j] += last_bit;
			j++;
			no = no >> 1;
		}
	}
	
	int p = 1;
	int ans = 0;
	for (int i = 0; i < 64; i++)
	{
		cnt[i] = cnt[i] % 3;
		ans += (cnt[i] * p);
		p = p << 1;
	}

	cout << ans << endl;
	return 0;
}