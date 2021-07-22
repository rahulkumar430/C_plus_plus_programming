#include<bits/stdc++.h>
using namespace std;

int main() {

	int arr[] = {1, 10, 11, 9, 100};
	int n = sizeof(arr) / sizeof(int);
	//search find

	int key;
	cin >> key;
	auto it = find(arr, arr + n, key);
	// cout << it << endl;
	// cout << it - arr << endl;		//to get the position
	int index = it - arr;
	if (index == n)
	{
		cout << "NOT PRESENT" << endl;
	}
	else {
		cout << index << endl;
	}
	return 0;
}