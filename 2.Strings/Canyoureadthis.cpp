#include <bits/stdc++.h>
using namespace std;

int actualSize(int num[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (num[i + 1] > num[i])
			count++;
	}
	return count;
}

void printElement(string S, int m, int n) {
	for (int i = m; i < n; i++) {
		cout << S[i];
	}
	cout << endl;
}

int main() {
	string S = "";
	getline(cin, S);

	int len = S.length();

	int num[len];							/* int num[len] = {0}; there will be an error called "Variable-sized 
								object 'num' may not be initialized”	so we have to set all the value to 0 by using memeset 
								but in some other editor and compiler you won't get the error SO TAKE CARE OF THAT */
	memset( num, 0, (len) * sizeof(int));

	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (isupper(S[i])) {
			num[j] = i;
			j++;
		}
	}

	int l = actualSize(num, len);

	cout << l << endl;

	int arr[l + 1];	/* int arr[l+1] = {0}; there will be an error called "Variable-sized 
								object 'arr' may not be initialized”	so we have to set all the value to 0 by using memeset 
								but in some other editor and compiler you won't get the error SO TAKE CARE OF THAT */
	memset( arr, 0, (l + 1) * sizeof(int));

	for (int i = 0; i < l; i++)
	{
		arr[i] = num[i];
	}
	arr[l] = len;

	for (int i = 0; i < l; i++)
	{
		printElement(S, arr[i], arr[i + 1]);
	}

	return 0;
}