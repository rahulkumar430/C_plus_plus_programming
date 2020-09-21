#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a[1000];
	int maxsum = 0;
	int currentsum = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		currentsum = currentsum + a[i];
		if (currentsum < 0) {
			currentsum = 0;
		}
		maxsum = max(currentsum, maxsum);
	}
	cout << "maximum sum is " << maxsum << endl;

	return 0;
}