#include <bits/stdc++.h>
using namespace std;

void divisor_count(int n) {
	vector<pair<int, int>> factors;
	int cnt;
	int divisor_cnt = 1;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			cnt = 0;
			while (n % i == 0) {
				cnt++;
				n = n / i;
			}
		}
		factors.push_back(make_pair(i, cnt));
	}
	if (n != 1) {
		factors.push_back(make_pair(n, 1));
	}
	for (int i = 0; i != factors.size(); i++)
	{
		divisor_cnt = divisor_cnt * (factors[i].second + 1);
	}
	cout << divisor_cnt << endl;
}

int main() {
	int no;
	cin >> no;

	divisor_count(no);

	return 0;
}