#include <bits/stdc++.h>
using namespace std;

int n;
int check[10][10];
int minimum = 100;

void updateMin(int **m) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (m[i][j] == 1 && check[i][j] != -1)
				count++;
		}
	}
	minimum = min(minimum, count);
}

void traverse( int ** m, int row, int col ) {
	//base cases
	if (row >= n || col >= n || row < 0 || col < 0)
		return;
	if (check[row][col] == -1 || m[row][col] == 0)
		return;

	//marking visited boxes with -1;
	check[row][col] = -1;
	
	updateMin(m);

	//recursive cases
	traverse( m,  row - 2,  col - 1 );
	traverse( m,  row - 2,  col + 1 );

	traverse( m,  row - 1,  col - 2 );
	traverse( m,  row - 1,  col + 2 );

	traverse( m,  row + 1,  col - 2 );
	traverse( m,  row + 1,  col + 2 );

	traverse( m,  row + 2,  col - 1 );
	traverse( m,  row + 2,  col + 1 );

	check[row][col] = 0;
}

/*
(r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1).
*/
int main() {

	cin >> n;
	int **m = new int*[n];
	for (int i = 0; i < n; i++) {
		m[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];

	memset(check, 0, sizeof(check));

	traverse(m, 0, 0);

	cout << minimum << endl;
	return 0;
}