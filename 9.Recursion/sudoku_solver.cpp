#include <bits/stdc++.h>
using namespace std;

void printMatrix(int mat[][25] , int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

bool canPlace(int mat[][25], int i, int j, int n, int num) {

	for (int x = 0; x < n; x++) {
		//Row and Col Check
		if (mat[x][j] == num or mat[i][x] == num) {
			return false;
		}
	}

	int rn = sqrt(n);
	int sx = (i / rn) * rn;
	int sy = (j / rn) * rn;

	for (int x = sx; x < sx + rn; x++) {
		for (int y = sy; y < sy + rn; y++ ) {
			if (mat[x][y] == num) {
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int mat[][25], int i, int j, int n) {
	//base case
	if (i == n) {
		//print the matrix
		printMatrix(mat, n);
		return true;
	}
	//Case row end
	if (j == n) {
		return solveSudoku(mat, i + 1, 0 , n);
	}
	// skip the pre filled cells
	if (mat[i][j] != 0) {
		return solveSudoku(mat, i, j + 1, n);
	}
	//recursive case
	//fill the current cell with possible options
	for (int num = 1; num <= n; num++) {
		if (canPlace(mat, i , j , n , num)) {
			//assume
			mat[i][j] = num;
			bool couldWeSolve = solveSudoku(mat, i, j + 1, n);
			if (couldWeSolve == true) {
				return true;
			}
		}
	}
	//backtracking here
	mat[i][j] = 0;
	return false;
}

int main() {
	int n;
	cin >> n;
	int mat[25][25] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	solveSudoku(mat, 0, 0, n);

	return 0;
}
