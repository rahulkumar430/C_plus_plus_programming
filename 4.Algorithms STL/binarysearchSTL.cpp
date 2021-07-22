#include<bits/stdc++.h>
using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 40, 40, 50, 100, 1000};
	int n = sizeof(arr) / sizeof(int);
	//search in a sorted array

	int key;
	cin >> key;
	bool present = binary_search(arr, arr + n, key);

	if (present)
	{
		cout << "present";
	}
	else {
		cout << "absent";
	}

	//to get the index
	//lower_bound(start,end,key) &  upper_bound(start,end,key)

	//lower_boun
	auto lb = lower_bound(arr, arr + n, 40);		//return greater than or equal to the key
	cout << "LOWER BOUND of 40 is : " << (lb - arr) << endl;

	if ((lb - arr) == n) {
		cout << "Element is not present.";
	}

	//upper_bound
	auto ub = upper_bound(arr, arr + n, 40);		//return strictly greater than the key
	cout << "UPPER BOUND of 40 is : " << (ub - arr) << endl;

	int freq = ub - lb;
	cout << freq << endl;


	return 0;
}