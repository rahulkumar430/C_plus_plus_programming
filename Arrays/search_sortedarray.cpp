#include<bits/stdc++.h>
using namespace std;

int search(int **mat, int m,int n, int x) 
{ 
    if (n == 0 and m==0) 
        return -1; 
    int smallest = mat[0][0];
    int  largest = mat[m - 1][n - 1]; 
    if (x < smallest || x > largest) 
        return -1; 
    // set indexes for top right element 
    int i = 0, j = n - 1;  
    while (i < m && j >= 0) { 
        if (mat[i][j] == x) { 
            cout << "n Found at "
                 << i << ", " << j; 
            return 1; 
        } 
        if (mat[i][j] > x) 
            j--; 
        else // if mat[i][j] < x 
            i++; 
    } 
  
    cout << "Element not found"; 
    return 0; // if ( i==n || j== -1 ) 
}


int main() {
	int m,n;
	cin >> m >> n;
	int **arr = new int*[m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int key;
	cin >> key;

	search(arr,m,n,key);
	
	return 0;
}