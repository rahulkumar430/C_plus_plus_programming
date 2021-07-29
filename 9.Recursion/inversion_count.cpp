#include <bits/stdc++.h>
using namespace std;

int merge(int *a, int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int k = s;

	int temp[10000];
	int cnt = 0;	//cross inversion count

	while (i <= mid and j <= e) {
		if (a[i] <= a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		}
		else {
			temp[k++] = a[j++];
			cnt += mid - i + 1;
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}
	for (int i = s; i <= e; i++)
	{
		a[i] = temp[i];
	}

	return cnt;
}

int inversion_count(int *arr, int s, int e) {
	if (s >= e) {
		return 0;
	}
	int mid = (s + e) / 2;
	int x = inversion_count(arr, s, mid);
	int y = inversion_count(arr, mid + 1, e);
	int z = merge(arr, s, e); //cross inversions
	return x + y + z;
}

int main() {
	int arr[] = {1, 5, 2, 6, 3, 0};
	int n = sizeof(arr) / sizeof(int);

	cout << inversion_count(arr, 0, n - 1) << endl;


	return 0;
}