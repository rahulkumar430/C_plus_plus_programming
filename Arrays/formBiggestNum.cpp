#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int myCompare(string s1, string s2)
{
	string X = s1;
	string Y = s2;

	string XY = X.append(Y);

	string YX = Y.append(X);

	return XY.compare(YX) > 0 ? 1 : 0;
}

int main() {

	int N;
	cin >> N;


	for (int j = 0; j < N; j++) {
		int n;
		cin >> n;
		vector<string> a(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		sort(a.begin(), a.end(), myCompare);

		string max = "";

		// int l = sizeof(a);

		for (int i = 0; i < n; i++) {
			max = max.append((a[i]));
		}

		cout<<max<<endl;

	}

	// for (int i = 0; i < N; i++)
	// {
	// 	cout << array[i] << endl;
	// }

	return 0;
}