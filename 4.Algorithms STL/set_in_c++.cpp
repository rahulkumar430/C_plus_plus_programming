#include <bits/stdc++.h>

using namespace std;

class Person
{
public:
	float age;
	string name;
	bool operator < (const Person& rhs) const {return age < rhs.age;}
};

int main()
{
	// empty set container //greater<int> is usd for putting elements in decreasing order
	set<int, greater<int> > s1;

	// insert elements in random order
	s1.insert(40);
	s1.insert(30);
	s1.insert(60);
	s1.insert(20);
	s1.insert(50);

	// only one 50 will be added to the set
	s1.insert(50);
	s1.insert(10);

	auto pos = s1.find(30);
	auto position = s1.find(20);

	cout << *position << endl;
	// prints the set elements
	cout << "The set elements after 30 are: ";
	for (auto it = pos; it != s1.end(); it++)
		cout << *it << " ";

// printing set s1
	set<int, greater<int> >::iterator itr;
	cout << "\nThe set s1 is : \n";
	for (itr = s1.begin(); itr != s1.end(); ++itr) {
		cout << ',' << *itr;
	}
	cout << endl;

// assigning the elements from s1 to s2
	set<int> s2(s1.begin(), s1.end());

// print all elements of the set s2
	cout << "\nThe set s2 after assign from s1 is : \n";
	for (itr = s2.begin(); itr != s2.end(); ++itr) {
		cout << ',' << *itr;
	}
	cout << endl;

// remove all elements up to 30 in s2
	cout << "\ns2 after removal of elements less than 30 :\n";
	s2.erase(s2.begin(), s2.find(30));
	for (itr = s2.begin(); itr != s2.end(); ++itr) {
		cout << ',' << *itr;
	}

// remove element with value 50 in s2
	int num;
	num = s2.erase(50);
	cout << "\ns2.erase(50) : ";
	cout << num << " removed\n";
	for (itr = s2.begin(); itr != s2.end(); ++itr) {
		cout << ',' << *itr;
	}

	cout << endl;

// lower bound and upper bound for set s1
	cout << "s1.lower_bound(40) : \n"
	     << *s1.lower_bound(40)
	     << endl;
	cout << "s1.upper_bound(40) : \n"
	     << *s1.upper_bound(40)
	     << endl;

// lower bound and upper bound for set s2
	cout << "s2.lower_bound(40) :\n"
	     << *s2.lower_bound(40)
	     << endl;
	cout << "s2.upper_bound(40) : \n"
	     << *s2.upper_bound(40)
	     << endl;

	set<Person> Set = {{30, "Rupesh"}, {25, "Hitesh"}, {22, "Rahul"}};
	for (const auto& e : Set) {
		cout << e.age << "  " << e.name << endl;
	}
	return 0;
}