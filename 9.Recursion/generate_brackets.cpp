#include <bits/stdc++.h>
using namespace std;
//Generate balanced brackets using N pairs of rounded brackets

//2 condition
// at any index i -> if you wanna put a opening bracket then open < N
// at any index i -> open > close
void generate_brackets(char *out, int n, int idx, int open, int close) {
	//base case
	if (idx == 2 * n) {
		out[idx] = '\0';
		cout << out << endl;
		return;
	}
	// rec case
	//2 options
	if (open < n) {
		out[idx] = '(';
		generate_brackets(out, n , idx + 1, open + 1, close);
	}
	if (close < open) {
		out[idx] = ')';
		generate_brackets(out, n, idx + 1, open, close + 1);
	}
	return;
}

int main() {
	int n;
	cin >> n;
	char out[1000];
	int idx = 0;
	generate_brackets(out, n , 0, 0, 0);
	return 0;
}