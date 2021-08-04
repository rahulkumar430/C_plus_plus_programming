#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = {10, 20, 11, 9, 8, 11, 10};
	int n = sizeof(arr) / sizeof(int);

	set<int> s;
	for (int i = 0; i < n; i++)
	{
		s.insert(arr[i]);
	}

	s.erase(10);

	auto it = s.find(11);
	s.erase(it);

	for (std::set<int>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout << *(i) << " ";
	}

	set<pair<int, int>> S;

	S.insert(make_pair(10, 1));
	S.insert(make_pair(5, 1));
	S.insert(make_pair(5, 3));
	S.insert(make_pair(20, 100));
	S.insert(make_pair(30, 35));
	S.insert(make_pair(40, 41));

	S.erase(S.find(make_pair(5, 3)));
	S.insert(make_pair(5, 4));

	for (auto p : S) {
		cout << p.first << " and " << p.second << endl;
	}
	cout <<endl;

	auto it1 = S.lower_bound(make_pair(20, 100));
	cout << it1->first << " and " << it1-> second << endl;

	auto it2 = S.upper_bound(make_pair(20, 100));
	cout << it2->first << " and " << it2-> second << endl;

	cout <<endl;

	auto it3 = S.lower_bound(make_pair(20, INT_MAX));
	cout << it3->first << " and " << it3-> second << endl;

	return 0;
}