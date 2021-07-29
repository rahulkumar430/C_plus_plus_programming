#include <bits/stdc++.h>
using namespace std;

//replace pi with 3.14

void replace_pi(char *a, int i) {
	if (a[i] == '\0' or a[i + 1] == '\0') {
		return;
	}
	if (a[i] == 'p' and a[i + 1] == 'i') {
		//shifting + replacement
		int j = i + 2;
		while (a[j] != '\0') {
			j++;//take j to the end of array
		}
		//shifting
		while (j >= i + 2) {
			a[j + 2] = a[j];	//copy the rest from right to left direction
			// we are doing j+2 , because already j = i+2 i.e. we have to shift two space more such that 4 space will remain
			j--;
		}
		//replacement
		a[i] = '3';
		a[i + 1] = '.';
		a[i + 2] = '1';
		a[i + 3] = '4';
		replace_pi(a, i + 4);
	}
	else {
		//go to the next position
		replace_pi(a, i + 1);
	}
	return;
}

int main() {
	char a[1000] = "xpigh";

	replace_pi(a, 0);
	cout << a << endl;
	return 0;
}