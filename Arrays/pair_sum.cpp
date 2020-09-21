#include<bits/stdc++.h>
using namespace std;
int main() {

	int a[] = {1, 3, 5, 7, 10, 11, 12, 13};
	int sum = 16;
//normal approach but N^2 complexity
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 8; j++) {
			if (a[i] + a[j] == sum) {
				cout << a[i] << " , " << a[j] << endl;
			}
		}
	}
	cout << endl;
// two pointer approach N complexity
	int i = 0;
	int j = sizeof(a) / sizeof(int) - 1;
	while (i < j) {
		int currentsum = a[i] + a[j];
		if (currentsum > sum) {
			j--;
		}
		else if (currentsum < sum) {
			i++;
		}
		else {
			cout << a[i] << " and " << a[j] << endl;
			i++;
			j--;
		}
	}

	return 0;
}