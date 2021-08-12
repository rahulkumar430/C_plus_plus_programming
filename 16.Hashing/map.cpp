#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, int> m;

	//1.Insert
	m.insert(make_pair("Mango", 100));

	pair<string, int> p;
	p.first = "Apple";
	p.second = 120;
	m.insert(p);

	m["Banana"] = 20;

	//2. Search
	string fruit;
	cin >> fruit;

	auto it = m.find(fruit);
	if (it != m.end()) {
		cout << "Price of " << fruit << " is " << m[fruit] << endl;
	}
	else {
		cout << "Fruit is not present." << endl;
	}

	//Another way to find a particular map
	//it stores unique keys only once
	//3.Update
	m["Banana"] = 30;	//It won't create another object rather it'll update the prev value.

	if (m.count(fruit)) {
		cout << "Price of " << fruit << " is " << m[fruit] << endl;
	}
	else {
		cout << "Fruit is not present." << endl;
	}

	//4.Erase
	m.erase(fruit);
	cout << m.count(fruit) << endl;

	m["Litchi"] = 160;
	m["Pineapple"] = 90;
	m["Pears"] = 80;
	//Iterate over all the key value pairs
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " : " << i->second << endl;	//Lexicographically sorted order
	}

	//for each loop
	/*
	for(auto i:m){
		cout << i->first<< " : "<< i->second << endl;
	}
	*/

	return 0;
}