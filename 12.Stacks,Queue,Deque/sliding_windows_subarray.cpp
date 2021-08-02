//SPOJ sliding windows problem - subarray
//https://www.spoj.com/problems/ARRAYSUB/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int a[100005];
	int k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;
	//We have to process first k elements separtely
	deque <int> Q(k);
	int i = 0;
	for (i = 0; i < k; i++) {
		while ( !Q.empty() && a[i] > a[Q.back()]) {
			Q.pop_back();
		}
		Q.push_back(i);
	}
	//process the remaining elements
	for (; i < n; i++) {
		cout << a[Q.front()] << " ";
		//1. remove the elements which are not the part of the window(contraction)
		while (!Q.empty() and (Q.front() <= i - k)) {
			Q.pop_front();
		}
		//2. Remove the elements which are not useful and are in the window
		while (!Q.empty() and (a[i] >= a[Q.back()])) {
			Q.pop_back();
		}
		//3. Add the new elements(Expansion)
		Q.push_back(i);
	}
	cout << a[Q.front()] << endl;
	return 0;
}