#include <bits/stdc++.h>
using namespace std;

void stockSpan(int prices[], int n, int span[]) {
	stack<int> s;
	s.push(0);

	span[0] = 1;

	for (int i = 1; i < n; i++)
	{
		int curr_price = prices[i];
		//topmost element that is higher then current prices
		while (!s.empty() and prices[s.top()] <= curr_price) {
			s.pop();
		}

		if (!s.empty()) {
			int prev_highest = s.top();
			span[i] = i - prev_highest;
		}
		else {
			span[i] = i + 1;
		}
		//push the element back into the stack
		s.push(i);
	}
}

int main() {
	int prices[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(prices) / sizeof(int);
	int span[100000] = {0};

	stockSpan(prices, n, span);

	for (int i = 0; i < n; i++)
	{
		cout << span[i] <<" ";
	}

	return 0;
}