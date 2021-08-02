#include <bits/stdc++.h>
using namespace std;

void transfer(stack <int> &s1, stack <int> &s2, int n) {
	for (int i = 0; i < n; i++)
	{
		s2.push(s1.top());
		s1.pop();
	}
}

void reverseStack(stack <int> &s1) {
	stack<int> s2;	//helper stack

	int n = s1.size();

	for (int i = 0; i < n; i++)
	{
		int x = s1.top();
		s1.pop();

		transfer(s1, s2, n - i - 1);
		s1.push(x);
		transfer(s2, s1, n - i - 1);
	}
}

int main() {
	stack<int> s;
	for (int i = 0; i <= 5; i++)
	{
		s.push(i);
	}

	reverseStack(s);

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}