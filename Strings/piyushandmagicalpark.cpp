#include<bits/stdc++.h>
using namespace std;

void magicalPark(char a[100][100], int n, int m, int k, int s) {		//k=threshold energy level  //s=strating energy level
	bool success = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			char ch = a[i][j];

			//check
			if (s < k) {
				success = false;
				break;
			}
			if (ch == '*') {
				s += 5;
			}
			else if (ch == '.') {
				s -= 2;
			}
			else {
				break;
			}
			//we loose one point when we move right except forthe last column
			if (j != m - 1) {
				s--;
			}
		}
	}
	if (success) {
		cout << "Yes" << endl;
		cout << s << endl;
	}
	else {
		cout << "No" << endl;
	}
}

int main() {
	int n, m, k, s;
	cin >> n >> m >> k >> s;

	char park[100][100];

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cin >> park[row][col];
		}
	}

	magicalPark(park, n, m, k, s);

	return 0;
}