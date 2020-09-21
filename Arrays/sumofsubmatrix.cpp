#include<bits/stdc++.h>
using namespace std;

int sumOfSubmatrix(int **arr, int n, int m) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tl = (i + 1) * (j + 1);	//tl=topleft
			int br = (n - i) * (m - j);	//br=bottomright
			sum += (tl * br) * arr[i][j];
		}
	}
	return sum;
}
int main(int argc, char const *argv[]) {  //https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/    <<---link to understand why we wrote int argc, char const *argv[]

	int n, m;
	cin >> n >> m;
	int **arr = new int*[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << sumOfSubmatrix(arr, n, m) << endl;
	// cout << argv[0];    //this holds the name of the program
    /*cout << "You have entered " << argc 
         << " arguments:" << "\n"; 
  
    for (int i = 0; i < argc; ++i) 
        cout << argv[i] << "\n"; 
*/
	return 0;
}