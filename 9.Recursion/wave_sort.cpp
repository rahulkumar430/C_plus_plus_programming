#include <bits/stdc++.h>
using namespace std;

/*
wave sorting -> every bigger is followed by a smaller element then again bigger and continues.
    b   b   b   b   b
	\  /\  /\  /\  /
	 \/  \/  \/  \/
	 s   s   s   s
*/


int main() {
	int a[] = {1, 3, 4, 2, 7, 4};
	int n = sizeof(a) / sizeof(int);

	for (int i = 0; i < n; i += 2)
	{
		//compare with prev element
		if (i != 0 and a[i] < a[i - 1])
		{
			swap(a[i], a[i - 1]);
		}
		//compare with next element
		if (i != (n - 1) and a[i] < a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}

	return 0;
}