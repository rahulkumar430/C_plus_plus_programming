#include <bits/stdc++.h>
using namespace std;

int stringToInt(char *a, int n) {
	if (n == 0)
		return 0;
	int digit = a[n - 1] - '0';
	int num = stringToInt(a, n - 1) * 10 + digit ;
	return num;
}

int main() {
	char a[] = "1234";
	int len = strlen(a);

	cout << stringToInt(a, len);
	return 0;
}