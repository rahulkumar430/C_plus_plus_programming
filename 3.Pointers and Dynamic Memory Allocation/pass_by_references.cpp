#include<bits/stdc++.h>
using namespace std;

//pass by value
void incrementval(int a) {
	a = a + 1;
	cout << "inside function:" << a << endl;	//it will be 11 //but oustside it is still 10
}

//pass by references
void incrementref(int *aptr){
	*aptr = *aptr + 1;
	cout << "inside function:" << *aptr << endl;
}

int main() {
	int a = 10;
	incrementval(a);
	cout << "inside main: " << a << endl;	
	incrementref(&a);
	cout << "inside main right now: " << a << endl;	
	
	return 0;
}