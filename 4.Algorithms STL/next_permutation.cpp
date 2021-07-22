#include<bits/stdc++.h>
using namespace std;

int main() {

// ************* Make your code more simple  **********//


	/*int **arr;
	int N;
	cin >> N;

	//create row heads
	arr = new int*[N];

	//create variable 2d array
	for (int i = 0; i < N; i++)
	{
		int C;
		cin >> C;
		for (int j = 0; j < C; j++)
		{
			int x;
			cin >> x;
			arr[i][j] = x;
		}
		next_permutation(&arr[i][0], &arr[i][C]);
		for (int j = 0; j < C; j++) {
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}

	delete [] arr;*/

	int tc;
    cin>>tc;
    while(tc--){
        int N;
	    cin >> N;
        int arr[N];

	    for (int i = 0; i < N; i++)
	    {
			cin >> arr[i];
		}
		next_permutation(arr,arr+N);
		for (int j = 0; j < N; j++) {
			cout << arr[j]<<" ";
		}
		cout << endl;
    }
	return 0;
}