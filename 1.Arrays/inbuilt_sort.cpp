#include<bits/stdc++.h>
using namespace std;
//if you pass the bool function i.e. compare as a parameter to the sort() then you can changer the order of sorting increasing or decreasing
bool compare(int a, int b) {
	//cout << "comparing " << a << " and " << b << endl;
	return a > b;  //Decreasing order
	//return a < b;  // increasing order
}

int main() {
	int n, key;
	cin >> n;

	int a[1000];

	for ( int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//Sort an array using sort() i.e. inbuilt sort function (#include<algorithm>)
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}