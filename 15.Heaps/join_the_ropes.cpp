#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement — Given N Ropes of different sizes, we have join the ropes together.
-----------------
The cost of joining 2 ropes of different sizes A and B is (A + B). Find the minimum cost to
join all the Ropes Together.
*/

int join_ropes(int ropes[], int n) {
	priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes + n);
	int cost = 0;
	while (pq.size() > 1) {
		int A = pq.top();
		pq.pop();

		int B = pq.top();
		pq.pop();

		int new_rope = (A + B);
		cost += new_rope;
		pq.push(new_rope);
	}
	return cost;
}

int main() {
	int ropes[] = {4, 3, 2, 6};
	int n = 4;
	cout << join_ropes(ropes, n) << endl;
	return 0;
}
