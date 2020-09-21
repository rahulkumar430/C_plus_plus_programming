#include<bits/stdc++.h>
using namespace std;

void spriralprint(int a[100][100], int m, int n) {
	int sr = 0;	//start row
	int sc = 0;	//start column
	int er = m - 1;	//end row
	int ec = n - 1;	//end column

	while (sr <= er and sc <= ec) {
		//start column
		if (ec > sc) {
			for (int i = sr; i <= er; i++) {
				cout << a[i][sc] << ", ";
			}
			sc++;
		}

		//end row
		if (er > sr) {
			for (int i = sc; i <= ec; i++) {
				cout << a[er][i] << ", ";
			}
			er--;
		}

		//end column
		for (int i = er; i >= sr; i--) {
			cout << a[i][ec] << ", ";
		}
		ec--;

		//start row
		for (int i = ec; i >= sc; i--) {
			cout << a[sr][i] << ", ";
		}
		sr++;

	}
	cout << "END" << endl;
}

int main() {
	int a[100][100] = {0};
	int m, n;
	cin >> m >> n;

	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cin >> a[row][col];
		}
	}
//spiral print

	spriralprint(a, m, n);

	return 0;
}