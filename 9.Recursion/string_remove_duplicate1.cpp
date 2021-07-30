// Recursive Program to remove consecutive duplicates from string S.
#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(char* S)
{
	// When string is empty, return
	if (S[0] == '\0')
		return;

	// if the adjacent characters are same
	if (S[0] == S[1]) {

		// Shift character by one to left
		int i = 0;
		while (S[i] != '\0') {
			S[i] = S[i + 1];
			i++;
		}

		// Check on Updated String S
		removeDuplicates(S);
	}

	// If the adjacent characters are not same
	// Check from S+1 string address
	removeDuplicates(S + 1);
}

// Driver Program
int main()
{
	char S[1001];
	cin >> S;
	removeDuplicates(S);
	cout << S << endl;

	return 0;
}
