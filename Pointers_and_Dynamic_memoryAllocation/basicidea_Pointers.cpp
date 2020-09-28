#include<bits/stdc++.h>
using namespace std;

int main() {
	int x = 10;
	int z = 20;
	cout << &x << endl;

	float y = 10.5;
	cout << &y << endl;

	//it doesn't work for character variables
	char ch = 'A';
	cout << &ch << endl;
	//explicit typecasting from char* to void*
	cout << (void *)&ch << endl;

	int *xptr;
	xptr = &x;

	cout << &x << endl;
	cout << xptr << endl;
	cout << *xptr << endl;
	cout << *(&x) << endl;

	cout << *(&xptr) << endl;
	cout << &(*xptr) << endl;

	//DOUBLE POINTER
	int **xxptr = &xptr;	
	cout << xxptr << endl;

	//we can reassign the pointer to somewhere else
	xptr = &z;
	cout << &z << endl;
	cout << xptr << endl;

	//basic calculation using [pointers]
	cout << *(xptr) + 1 << endl;
	cout << *(xptr + 1) << endl;

	return 0;
}