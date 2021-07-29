#include <bits/stdc++.h>
using namespace std;

void duplicate_formatting(char *a, int i) {
	if (a[i] == '\0' or a[i + 1] == '\0') {
		return;
	}
	if (a[i] == a[i + 1]) {
		int j = i + 2;
		while (a[j] != '\0') {
			j++;//take j to the end of array
		}
		//shifting
		while (j >= i + 1) {
			a[j + 1] = a[j];	//copy the rest from right to left direction
			j--;
		}
		//replacement
		a[j+1] = '*';
		duplicate_formatting(a, i + 2);
	}
	else {
		//go to the next position
		duplicate_formatting(a, i + 1);
	}
	return;
}

int main() {
	char a[1000];
	cin >> a;

	duplicate_formatting(a, 0);
	cout << a << endl;
	return 0;
}