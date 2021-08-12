#include <bits/stdc++.h>
using namespace std;

//Everything is same as map
//Only thing you want to change is - instead of #include<map> it'll be #include<unordered_map>
//unordered_map< key , value > um;
//Output will not be sorted as lexicographically

int main() {
	unordered_map<string, int> um;

	//1.Insert
	um.insert(make_pair("Mango", 100));

	pair<string, int> p;
	p.first = "Apple";
	p.second = 120;
	um.insert(p);

	um["Banana"] = 20;

	//2. Search
	string fruit;
	cin >> fruit;

	auto it = um.find(fruit);
	if (it != um.end()) {
		cout << "Price of " << fruit << " is " << um[fruit] << endl;
	}
	else {
		cout << "Fruit is not present." << endl;
	}

	//Another way to find a particular map
	//it stores unique keys only once
	//3.Update
	um["Banana"] = 30;	//It won't create another object rather it'll update the prev value.

	if (um.count(fruit)) {
		cout << "Price of " << fruit << " is " << um[fruit] << endl;
	}
	else {
		cout << "Fruit is not present." << endl;
	}

	//4.Erase
	um.erase(fruit);
	cout << um.count(fruit) << endl;

	um["Litchi"] = 160;
	um["Pineapple"] = 90;
	um["Pears"] = 80;
	//Iterate over all the key value pairs
	for (auto i = um.begin(); i != um.end(); i++)
	{
		cout << i->first << " : " << i->second << endl;	//Lexicographically sorted order
	}

	//for each loop
	/*
	for(auto p:um){
		cout << i->first<< " : "<< i->second << endl;
	}
	*/

	return 0;
}

