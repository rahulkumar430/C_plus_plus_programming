#include <bits/stdc++.h>
using namespace std;

char keypad[][10] = { "", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
static int cnt = 0;
void generate_names(char *in, char *out, int i, int j) {
	//base case

	if (in[i] == '\0') {
		out[j] == '\0';
		cout << out << endl;
		cnt++;
		return;
	}
	//rec case
	int digit = in[i] - '0';
	/*if (digit == 1 or digit == 0) {
		generate_names(in, out, i + 1, j);
	}*/
	for (int k = 0; keypad[digit][k] != '\0'; k++) {
		out[j] = keypad[digit][k];
		//fill the remaining part
		generate_names(in, out, i + 1, j + 1);
	}
	return;
}

int main() {
	char in[100];
	cin >> in;

	char out[100];
	generate_names(in, out, 0, 0);
	cout << cnt << endl;
	//cout << keypad[4][2];
	return 0;
}