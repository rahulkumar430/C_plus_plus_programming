#include <bits/stdc++.h>
using namespace std;

typedef multiset<int>::iterator It;

int main() {

	int arr[] = {10, 20, 30, 20, 30, 80, 90, 30, 30, 30, 10, 10};
	int n = sizeof(arr) / sizeof(int);
	multiset<int> m(arr, arr + n);

	//3. Erase
	cout << m.erase(20) << endl;

	//1. Iterator
	for (int x : m) {
		cout << x << ",";
	}
	//2. Count Function
	m.insert(68);
	cout << endl;
	cout << "Count: " <<m.count(68) << endl;

	//4. Find
	auto it = m.find(30);
	cout << (*it) << endl;

	//5. Equal Range

	pair<It, It> range = m.equal_range(10);
	for (auto it = range.first; it != range.second; it++) {
		cout << *it << endl;
	}


	//Lower Bound and Upper Bound
	for (auto it = m.lower_bound(10); it != m.upper_bound(77); it++) {
		cout << *it << ",";
	}

	return 0;
}
