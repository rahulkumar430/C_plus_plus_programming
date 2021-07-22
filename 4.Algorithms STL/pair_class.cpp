#include<bits/stdc++.h>
using namespace std;


// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
	return (a.second < b.second);
}


int main() {

	pair<int, char> p;
	p.first = 10;
	p.second = 'B';

	//another way
	pair<int, char> p2(p);

	cout << p2.first << endl;
	cout << p2.second << endl;

	//make pair

	pair<int, string> p3 = make_pair(100, "Audi");
	cout << p3.first << "  " << p3.second << endl;

	int a, b;
	cin >> a >> b;

	pair<int, int> p4 = make_pair(a, b);
	cout << p4.first << "  " << p4.second << endl;

	//we can make array of pairs & vector of pairs & pair of pairs
	//array of pairs
	pair<int, int> adjs[] = {make_pair(1, 2), make_pair(3, 4)};
	cout << "{ " << adjs[0].first << ", " << adjs[1].second << " }" << endl;

	//pair of pairs
	pair<pair<int, int>, string> car;

	car.second = "bmw";
	car.first.first = 10;
	car.first.second = 20;

	cout << car.first.first << " " << car.first.second << "  " << car.second << endl;

	pair<int, int>pair1 = make_pair(1, 12);
	pair<int, int>pair2 = make_pair(9, 12);


	cout << (pair1 == pair2) << endl;
	cout << (pair1 != pair2) << endl;
	cout << (pair1 >= pair2) << endl;
	cout << (pair1 <= pair2) << endl;
	cout << (pair1 > pair2) << endl;
	cout << (pair1 < pair2) << endl;

	cout << "Before swapping:\n " ;
	cout << "Contents of pair1 = " << pair1.first << " " << pair1.second << " ";
	cout << "Contents of pair2 = " << pair2.first << " " << pair2.second << " ";
	pair1.swap(pair2);

	cout << "\nAfter swapping:\n ";
	cout << "Contents of pair1 = " << pair1.first << " " << pair1.second << " ";
	cout << "Contents of pair2 = " << pair2.first << " " << pair2.second << " ";


	//vector of pairs
	vector< pair <int, int> > vect;

	// initialising 1st and 2nd element of
	// pairs with array values
	int arr[] = {10, 20, 5, 40 };
	int arr1[] = {30, 60, 20, 50};
	int n = sizeof(arr) / sizeof(arr[0]);

	// Entering values in vector of pairs
	for (int i = 0; i < n; i++)
		vect.push_back( make_pair(arr[i], arr1[i]) );

	// Printing the vector
	for (int i = 0; i < n; i++)
	{
		// "first" and "second" are used to access
		// 1st and 2nd element of pair respectively
		cout << vect[i].first << " "
		     << vect[i].second << endl;
	}

	// Using simple sort() function to sort
	sort(vect.begin(), vect.end());

	// Printing the sorted vector(after using sort())
	cout << "The vector after sort operation is:\n" ;
	for (int i = 0; i < n; i++)
	{
		// "first" and "second" are used to access
		// 1st and 2nd element of pair respectively
		cout << vect[i].first << " "
		     << vect[i].second << endl;
	}


	// Using sort() function to sort by 2nd element
	// of pair
	sort(vect.begin(), vect.end(), sortbysec);

	// Printing the sorted vector(after using sort())
	cout << "The vector after sort operation is:\n" ;
	for (int i = 0; i < n; i++)
	{
		// "first" and "second" are used to access
		// 1st and 2nd element of pair respectively
		cout << vect[i].first << " "
		     << vect[i].second << endl;
	}


	return 0;
}