#include<bits/stdc++.h>
using namespace std;

void dislay(int a[100][100] , int n) {
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cout << a[row][col] << "  ";
		}
		cout << endl;
	}
}

void rotate(int a[100][100], int n) {

	//reverse each row ->  1 2 3 4  -->>  4 3 2 1
	for (int row = 0; row < n; row++) {
		int sc = 0;
		int ec = n - 1;
		while (sc < ec) {
			swap(a[row][sc], a[row][ec]);
			sc++;
			ec--;
		}
	}
	//to take transpose
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				swap(a[i][j], a[j][i]);
			}
		}
	}

}

void rotate_stl(int a[100][100], int n) {
//same thing using STL ->   reverse(start_container,end_container)
	for (int i = 0; i < n; i++) {
		reverse(a[i], a[i] + n);
	}

	//to take transpose
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				swap(a[i][j], a[j][i]);
			}
		}
	}

}


int main() {
	int  n;
	cin >> n;

	int a[100][100];

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> a[row][col];
		}
	}
	cout << endl;
	rotate_stl(a, n);
	dislay(a, n);

	rotate(a, n);
	dislay(a, n);

	return 0;
}