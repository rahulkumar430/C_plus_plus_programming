#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
	//cout << "comparing " << a << " and " << b << endl;
	return a < b;  //Decreasing order
	//return a > b;  // increasing order
}

bool compareCopy(int c , int d){
	return c>d;
}

void bubble_sort(int a[], int n, bool (&cmp)(int c, int d)) { // i've entered int c and int d, but still it will 
//take compare function as parameter cause below in main function i've passed compare not compareCopy !!

	//one iteration = one element sorted
	for (int itr = 1; itr <= n - 1; itr++)
	{
		//pairwaise swapping for unsorted part of the array
		for (int j = 0; j <= ((n - 1) - itr); j++) {
			if (cmp(a[j] , a[j + 1])) {
				swap (a[j], a[j + 1]);
			}
		}
	}
}

int main() {
	int n, key;
	cin >> n;

	int a[1000];

	for ( int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bubble_sort(a, n, compare);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}