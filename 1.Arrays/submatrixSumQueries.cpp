// C++ program to compute submatrix query sum in O(1) time
#include<iostream>
using namespace std;

#define M 4
#define N 5

// Function to preprcess input mat[M][N]. This function
// mainly fills aux[M][N] such that aux[i][j] stores sum
// of elements from (0,0) to (i,j)
int preProcess(int mat[M][N], int aux[M][N])
{
// Copy first row of mat[][] to aux[][]
	for (int i = 0; i < N; i++)
		aux[0][i] = mat[0][i];

// Do column wise sum
	for (int i = 1; i < M; i++)
		for (int j = 0; j < N; j++)
			aux[i][j] = mat[i][j] + aux[i - 1][j];

// Do row wise sum
	for (int i = 0; i < M; i++)
		for (int j = 1; j < N; j++)
			aux[i][j] += aux[i][j - 1];
}

// A O(1) time function to compute sum of submatrix
// between (tli, tlj) and (rbi, rbj) using aux[][]
// which is built by the preprocess function
int sumQuery(int aux[M][N], int tli, int tlj, int rbi,
             int rbj)
{
	int sum;
	if (tli == 0 and tlj ==0) {
		sum = aux[rbi][rbj];
	}
	else if (tli == 0) {
		sum = aux[rbi][rbj] - aux[rbi][tlj - 1];
	}
	else if (tlj == 0) {
		sum = aux[rbi][rbj] - aux[tli - 1][rbj];
	}
	else {
		sum = aux[rbi][rbj] - aux[tli - 1][rbj] - aux[rbi][tlj - 1] + aux[tli - 1][tlj - 1] ;
	}
	return sum;
}

// Driver program
int main()
{
	int mat[M][N] = {{1, 2, 3, 4, 6},
		{5, 3, 8, 1, 2},
		{4, 6, 7, 5, 5},
		{2, 4, 8, 9, 4}
	};
	int aux[M][N];

	preProcess(mat, aux);

	int tli = 2, tlj = 2, rbi = 3, rbj = 4;
	cout << "\nQuery1: " << sumQuery(aux, tli, tlj, rbi, rbj);

	tli = 0, tlj = 0, rbi = 1, rbj = 1;
	cout << "\nQuery2: " << sumQuery(aux, tli, tlj, rbi, rbj);

	tli = 1, tlj = 2, rbi = 3, rbj = 3;
	cout << "\nQuery3: " << sumQuery(aux, tli, tlj, rbi, rbj);

	return 0;
}
