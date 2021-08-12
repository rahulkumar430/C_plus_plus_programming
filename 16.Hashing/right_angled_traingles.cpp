/*
Right Angles Triangles
GIven N points in a 2D Cartesian plane, Howmany right angled triangles are there
such that perpendicular or base is parallel to X or Y axis?
*/

#include <bits/stdc++.h>
using namespace std;

int RightAngled(int a[][2], int n)
{

	// To store the number of points has same x or y coordinates
	unordered_map<int, int> x;
	unordered_map<int, int> y;

	for (int i = 0; i < n; i++) {
		x[a[i][0]]++;
		y[a[i][1]]++;
	}

	int count = 0;

	// Iterate to check for total number of possible triangle
	for (int i = 0; i < n; i++) {
		if (x[a[i][0]] >= 1 and y[a[i][1]] >= 1) {
			count += (x[a[i][0]] - 1) * (y[a[i][1]] - 1);
		}
	}
	return count;
}

int main()
{
	int n = 5;

	int arr[][2] = { { 1, 2 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 3, 2 }};

	cout << RightAngled(arr, n) << endl;

	return 0;
}
