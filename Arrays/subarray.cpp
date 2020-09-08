#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;

	int a[1000];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

//generate all the subarrays
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n ; j++)
		{
			//elements of subarray(i,j)
			for (int k = i; k <= j; k++)
			{
				cout << a[k] << ",";
			}
			cout << endl;
		}
	}

	return 0;
}