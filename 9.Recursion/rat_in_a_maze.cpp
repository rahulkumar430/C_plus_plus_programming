#include <bits/stdc++.h>
using namespace std;

static int cnt = 0;

bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n) {
	if (i == m and j == n ) {
		soln[m][n] = 1;
		//Print the Path
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cnt++;
		return true;
	}
	//Rat should be inside grid
	if (i > m or j > n) {
		return false;
	}
	if (maze[i][j] == 'X') {
		return false;
	}
	//Assume solution exists through current cell
	soln[i][j] = 1;

	//Recursive case
	bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
	bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);
	
	//Backtracking
	soln[i][j] = 0;

	if (rightSuccess || downSuccess) {
		return true;
	}
	return false;
}

int main() {
	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};
	int soln[10][10] = {0};
	int m = 4;
	int n = 4;

	bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
	cout << "Number of paths: " << cnt << endl;

	if (ans == false) {
		cout << "Path idoesn't exist !" << endl;
	}

	return 0;
}