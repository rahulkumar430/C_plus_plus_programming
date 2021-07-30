// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;


// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string a, int l, int r, set <string> &S)
{
	// Base case
	if (l == r)
		S.insert(a);

	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l + 1, r, S);

			//backtrack
			swap(a[l], a[i]);
		}
	}
}

// Driver Code
int main()
{
	string str;
	cin >> str;
	int n = str.size();
	set <string> S;
	permute(str, 0, n - 1, S);
	for (auto it = S.begin(); it != S.end(); it++)
		cout << *it << endl;
	return 0;
}