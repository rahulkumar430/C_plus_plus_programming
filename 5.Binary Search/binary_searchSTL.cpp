#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, key;
	cin >> n;

	int a[1000];

	for ( int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Enter the element that you wanna search :";
	cin >> key;

	bool present = binary_search(a, a + n, key);

	if (present)
	{
		cout << "Present !!";
	}
	else {
		cout << "Absent !!";
	}

	//to get the index
	//lower_bound(start,end,key) &  upper_bound(start,end,key)

	//lower_boun
	auto lb = lower_bound(a, a + n, key);		//return greater than or equal to the key
	cout << "LOWER BOUND of 40 is : " << (lb - a) << endl;

	if ((lb - a) == n) {
		cout << "Element is not present.";
	}

	//upper_bound
	auto ub = upper_bound(a, a + n, key);		//return strictly greater than the key
	cout << "UPPER BOUND of 40 is : " << (ub - a) << endl;

	int freq = ub - lb;
	cout << freq << endl;

	return 0;
}