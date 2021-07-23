#include<bits/stdc++.h>
using namespace std;

float square_root(int n, int p) {

	int s = 0;
	int e = n - 1;

	float ans = -1;

	while (s <= e) {
		int mid = (s + e) >> 1;	//using right shift  //or mid = (s+e)/2
		//link to understand right and left shift //https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/

		if (mid * mid == n)
		{
			return mid;
		}

		if (mid * mid < n) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	float inc = 0.1;
	for (int times = 1; times <= p; times++)
	{
		while (ans * ans <= n) {
			ans = ans + inc;
		}

		ans = ans - inc;
		inc = inc / 10;
	}


	return ans;
}


int main() {
	int m, n, p;	//p = precision
	cin >> n >> p >> m; 

	cout << square_root(n, p) << endl;

	cout << fixed << setprecision(10) << sqrt(m) << endl;

	return 0;
}