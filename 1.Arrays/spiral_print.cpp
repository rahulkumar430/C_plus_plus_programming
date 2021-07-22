#include<bits/stdc++.h>
using namespace std;

void spriralprint(int a[1000][1000], int m, int n) {
	int sr = 0;	//start row
	int sc = 0;	//start column
	int er = m - 1;	//end row
	int ec = n - 1;	//end column

	while (sr <= er and sc <= ec) {
		//start row
		for (int i = sc; i <= ec; i++) {
			cout << a[sr][i] << "  ";
		}
		sr++;

		//end column
		for (int i = sr; i <= er; i++) {
			cout << a[i][ec] << "  ";
		}
		ec--;

		//end row
		if (er > sr) {
			for (int i = ec; i >= sc; i--) {
				cout << a[er][i] << "  ";
			}
			er--;
		}

		//start column
		if (ec > sc) {
			for (int i = er; i >= sr; i--) {
				cout << a[i][sc] << "  ";
			}
			sc++;
		}
	}

}

int main() {
	int a[1000][1000] = {0};
	int m, n;
	cin >> m >> n;

	int val = 1;
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			a[row][col] = val;
			val++;
			cout << a[row][col] << "  ";
		}
		cout << endl;
	}
//spiral print

	spriralprint(a, m, n);

	return 0;
}