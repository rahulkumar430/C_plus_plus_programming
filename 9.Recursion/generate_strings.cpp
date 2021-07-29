#include <bits/stdc++.h>
using namespace std;
//given 1 - A, 2 - B, ....., 11 - K, .... , 26 - Z
//So you need to generate howmany different types of string you can generate with the given number
void generate_strings(char *in, char *out, int i, int j) {
	//base case
	if (in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	//rec case
	//2 options

	//one digit at a time
	int digit = in[i] - '0';
	//if digit came out to be zero then we have to skip it for this case and it will automatically get selected for 2 digits at a time 
	// corner case
	if (digit == 0) {
		i++;
		digit = in[i] - '0';
	}
	char ch = digit + 'A' - 1;
	out[j] = ch;
	generate_strings(in, out, i + 1, j + 1);

	//two digit at a time
	if (in[i + 1] != '\0') {
		int secondDigit = in[i + 1] - '0';
		int no = digit * 10 + secondDigit;
		if (no <= 26) {
			ch = no + 'A' - 1;
			out[j] = ch;
			generate_strings(in, out, i + 2, j + 1);
		}
	}
	return;
}

int main() {
	char a[100];
	cin >> a;

	char out[100];
	generate_strings(a, out, 0, 0);
	return 0;
}