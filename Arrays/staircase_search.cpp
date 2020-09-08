#include<bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	int i, j;
	cout << "Enter the no. of rows and columns" << endl;
	cin >> m >> n;
	int a[10][10];
	for ( i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> a[i][j];

		}
	}
	cout << "Enter the no. to be searched" << endl;
	int x;
	cin >> x;
	i = 0;
	j = n - 1;

	while (i < m && j < n) {
		if (a[i][j] == x) {
			cout << "No. found at row = " << i + 1 << " column = " << j + 1 << endl;
			break;
		}
		else if (x < a[i][j]) {
			j--;

		}
		else {
			i++;
		}
	}
		
	return 0;
}