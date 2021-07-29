#include <bits/stdc++.h>
using namespace std;

int profit(int n, int c, int *wt, int *prices) {
	//base case
	if (n == 0 or c == 0)
		return 0;
	//rec case
	int ans = 0;
	int inc, exc;
	inc = exc = 0;
	//include
	if (wt[n - 1] <= c) {
		inc = prices[n - 1] + profit(n - 1, c - wt[n - 1], wt, prices);
	}
	//exclude
	exc = profit(n - 1, c, wt, prices) ;

	ans = max(inc, exc);
	return ans;
}

int main() {
	int weights[] = {1, 2, 3, 5};
	int prices[] = {40, 20, 30, 100};

	int N = 4;
	int C = 7;

	cout << profit(N, C, weights, prices);
	return 0;
}