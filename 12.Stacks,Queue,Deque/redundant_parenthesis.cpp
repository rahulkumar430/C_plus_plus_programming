#include <bits/stdc++.h>
using namespace std;

bool checkRedundancy(string& str)
{
	// create a stack of characters
	stack<char> Stack;

	// Iterate through the given expression
	for (char ch : str)
	{
		// if current character is close parenthesis ')'
		if (ch == ')')
		{
			// pop character from the stack
			char top = Stack.top();
			Stack.pop();

			// stores the number of characters between a
			// closing and opening parenthesis
			// if this count is less than or equal to 1
			// then the brackets are redundant else not
			int elementsInside = 0;
			while (top != '(')
			{
				elementsInside++;
				top = Stack.top();
				Stack.pop();
			}
			if (elementsInside < 1) {
				return 1;
			}
		}

		// push open parenthesis '(', operators and
		// operands to stack
		else
			Stack.push(ch);
	}

	// No duplicates found
	return false;
}

// Function to check redundant brackets
void findRedundant(string& str)
{
	bool ans = checkRedundancy(str);
	if (ans == true)
		cout << "Yes\n";
	else
		cout << "No\n";
}

// Driver code
int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		string str;
		cin >> str;

		findRedundant(str);
	}

	return 0;
}
//	https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
//	https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/