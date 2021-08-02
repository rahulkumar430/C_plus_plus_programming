#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack <int> &s, int x) {
	//base case
	if(s.empty()){
		s.push(x);
		return;
	}
	//recursive case
	int data = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(data);
}

void rec_reverseStack(stack <int> &s) {
	//base case
	if(s.empty()){
		return;
	}
	//otherwise
	//pop out the top element and insert it at the bottom of reversed smaller stack
	int x = s.top();
	s.pop();
	//rec reverse smaller stack
	rec_reverseStack(s);
	insertAtBottom(s,x);
}

int main() {
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		s.push(i);
	}

	rec_reverseStack(s);

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}