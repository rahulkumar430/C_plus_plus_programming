//Aggressive Cows Problem
#include<bits/stdc++.h>
using namespace std;

bool canPlaceCows(int stalls[], int n, int c, int min_sep) {

	int last_cow = stalls[0];
	//place the first cow int the first stall
	int count = 1;

	for (int i = 1; i < n; i++)
	{
		if (stalls[i] - last_cow >= min_sep) {
			last_cow = stalls[i];
			count++;
			if (count == c) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int stalls[n] = {0};

	int cows;
	cin >> cows;

	for (int i = 0; i < n; i++)
	{
		cin >> stalls[i];
	}
    sort(stalls, stalls + n);
	int s = 0;
	int e = stalls[n - 1] - stalls[0];

	int ans = 0;

	while (s <= e) {

		int mid = (s + e) / 2;

		bool cowsCanStay = canPlaceCows(stalls, n, cows, mid);
		if (cowsCanStay) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}

	}

	cout << ans << endl;
	return 0;
}