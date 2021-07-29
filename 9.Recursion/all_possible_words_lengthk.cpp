// C++ program to print all
// possible strings of length k
#include <bits/stdc++.h>
using namespace std;

static int cnt = 0;
// The main recursive method
// to print all possible
// strings of length k
void printAllKLengthRec(char set[], string prefix, int n, int k)
{

	// Base case: k is 0,
	// print prefix
	if (k == 0)
	{
		cout << (prefix) << endl;
		cnt++;
		return;
	}

	// One by one add all characters
	// from set and recursively
	// call for k equals to k-1
	for (int i = 0; i < n; i++)
	{
		string newPrefix;

		// Next character of input added
		newPrefix = prefix + set[i];

		// k is decreased, because
		// we have added a new character
		printAllKLengthRec(set, newPrefix, n, k - 1);
	}

}

void printAllKLength(char set[], int k, int n)
{
	printAllKLengthRec(set, "", n, k);
}

// Driver Code
int main()
{

	cout << "First Test" << endl;
	char set1[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int k = 3;
	printAllKLength(set1, k, 3);
	cout << cnt;

	/*cout << "Second Test\n";
	char set2[] = {'a', 'b', 'c', 'd'};
	k = 1;
	printAllKLength(set2, k, 4);*/
	return 0;
}

// https://www.geeksforgeeks.org/print-all-combinations-of-given-length/
