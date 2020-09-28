#include<bits/stdc++.h>
using namespace std;

int main() {
	//allocation + deallocation = is done by compiler
	int b[100] = {0}; 	//start with zeros
	cout << sizeof(b) << endl;
	cout << b << endl;   // comes from symbol table
	//here b cant be overwritten cause it is a part of Read Only Memory

	// dynamic allocation
	int n;
	cin >> n;
	int *a = new int[n]{0}; // start with zeros
	cout<<sizeof(a)<<endl;
	cout<<a<<endl;	// comes from variable thta is created inside the static memory -> can be overwritten

	//no change
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cout << a[i] << " ";
	}

	//deallocation of delete 
	delete [] a;

	return 0;
}