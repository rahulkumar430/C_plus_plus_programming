#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	cin >> c;
	if (islower(c))
		cout << "lowercase";
	else if (isupper(c))
		cout << "UPPERCASE";
	else
		cout << "Invalid";

	return 0;
}