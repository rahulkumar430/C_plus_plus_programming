#include <bits/stdc++.h>
using namespace std;

int main() {
	list<int> l;
	list<int> l1{1, 2, 3, 10, 5, 9};
	list<string> l2{"apple", "guava", "banana", "mango"};
	l2.push_back("pineapple");

	for (string s : l2) {
		cout << s << "-->";
	}
	cout << endl;

	l2.sort();

	l2.reverse();
	//pop front
	cout << l2.front() << endl;
	l2.pop_front();
	//push back
	l2.push_back("kiwi");
	cout << l2.back() << endl;
	//pop back
	l2.pop_back();

	//iterate
	for (auto it = l2.begin(); it != l2.end(); it++)
	{
		cout << (*it) << "-->";
	}
	cout << endl;

	l2.push_back("guava");
	l2.push_back("orange");

	//remove a fruit
	string f;
	cin >> f;
	l2.remove(f);
	//l2.remove("orange");
	for (string s : l2) {
		cout << s << "-->";
	}
	cout << endl;
	//erase one or more elements
	/* auto it = l2.begin();
	it++;
	l2.erase(it); */

	//insert
	auto it = l2.begin();
	it++;
	l2.insert(it, "Strawberry");
	for (string s : l2) {
		cout << s << "-->";
	}
	cout << endl;

	return 0;
}