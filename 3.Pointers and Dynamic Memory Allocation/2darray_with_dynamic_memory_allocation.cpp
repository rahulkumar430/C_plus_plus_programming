#include<bits/stdc++.h>
using namespace std;

int main() {

	int **arr;
	int r, c;
	cin >> r >> c;
	
	//https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/

	//create row heads
	arr = new int*[r];

	//create 2d array
	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[c];
	}
	int val = 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			arr[i][j] = val;
			val++;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	delete [] arr;

	return 0;
}