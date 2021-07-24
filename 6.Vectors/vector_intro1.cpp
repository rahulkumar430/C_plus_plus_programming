#include<bits/stdc++.h>
using namespace std;
int main() {

	vector <int> v;
	//everytime you push_back the capacity changes i.e. doubles and for larger implementation it takes alot of time.
	//so to avoid this we use reserve function.

	int n;
	cin >> n;

	//v.reserve(1000);

	for (int i = 0; i <= n; i++)
	{
		int no;
		cin >> no;
		v.push_back(i);
		cout << "changing capacity :" << v.capacity() << endl;
	}

	for (int x : v)
	{
		cout << x << ",";
	}

	return 0;
}