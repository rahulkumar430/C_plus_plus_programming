#include<bits/stdc++.h>
using namespace std;
int main() {

	vector <int> v;

	for (int i = 0; i <= 5; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << "\n";
	v.pop_back();

	for (auto element : v) {
		cout << element << endl;
	}

	vector<int> v2 (3, 50);	// insert some elements in the middle
	for (auto element : v2) {
		cout << element << endl;
	}
	swap(v, v2);	//swap elements of both vectors
	for (auto element : v2) {
		cout << element << endl;
	}
	cout << "\n";
	for (auto element : v) {
		cout << element << endl;
	}

	cout << "size: " << v.size() << endl;
	cout << "capacity: " << v.capacity() << endl;	//size of underlying array
	cout << "Max_size :" << v.max_size() << endl;	//maximum no of elements a vector can hold in the worst case acc to available memory in the system

	if (v.empty()) {
		cout << "vector is empty" << endl;
	}
	else cout << "vector is not empty" << endl;

	cout << "first element: " << v2.front() << endl;
	cout << "last element: " << v2.back() << endl;
	cout << "Element at 3rd index: " << v2.at(3) << endl;

	vector<int> d{1, 2, 3, 4, 5};

	d.erase(d.begin() + 1);	//erase some element in the middle
	for (auto element : d) {
		cout << element << endl;
	}

	d.erase(d.begin() + 2, d.begin() + 4);	//erase multiple elements in the middle
	for (auto element : d) {
		cout << element << endl;
	}

	d.resize(8);	//avoid shrink		//if the size is increasing then more memory will be allocated
	cout << d.capacity() << endl;
	for (auto element : d) {
		cout << element << endl;
	}

	d.clear();	//capacity will be same as old but size will become zero (0); 	//doesn't delete memory occupied

	if (d.empty()) {
		cout << "This is an empty vector." << endl;
	}

	cout << d.front() << endl;
	cout << d.back() << endl;

	return 0;
}