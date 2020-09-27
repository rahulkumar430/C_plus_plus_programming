#include <bits/stdc++.h>
using namespace std;

void printCharWithFreq(string str)
{
	// size of the string 'str'
	int n = str.size();

	// 'freq[]' implemented as hash table
	int freq[1000];

	// initialize all elements of freq[] to 0
	memset(freq, 0, sizeof(freq));

	// accumulate freqeuncy of each character in 'str'
	for (int i = 0; i < n; i++)
		freq[str[i] - ' ']++;

	// traverse 'str' from left to right
	for (int i = 0; i < n; i++) {

		// if frequency of character str[i] is not
		// equal to 0
		if (freq[str[i] - ' '] != 0) {

			// print the character along with its
			// frequency
			cout << str[i] << freq[str[i] - ' '];

			// update frequency of str[i] to 0 so
			// that the same character is not printed
			// again
			freq[str[i] - ' '] = 0;
		}
	}
}

int main() {
	string S = "";
	getline(cin, S);

	if (S.length() < 1) {
		return 0;
	}
	else
		printCharWithFreq(S);

	return 0;
}