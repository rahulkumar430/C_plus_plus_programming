#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a[1000];
	int cumsum[1000] = {0};
	int maxsum = 0;
	int currentsum = 0;

	int left = -1;
	int right = -1;

	cin >> a[0];
	cumsum[0] = a[0];

	for (int i = 1; i < n; ++i)
	{
		cin >> a[i];
		//along with taking input we can update the cumsumarray !!
		cumsum[i] = cumsum[i - 1] + a[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) {
			currentsum = 0;
			//the line below is the formula to get the sum from one end to another end
			currentsum = cumsum[j] - cumsum[i - 1];
			//update the maxsum with an if case !
			if (currentsum > maxsum) {
				maxsum = currentsum;
				left = i;
				right = j;
			}

		}
	}
	cout << "maximum sum is " << maxsum << endl;

	for (int m = left; m <= right; m++) {
		cout << a[m] << " ";
	}
	return 0;
}