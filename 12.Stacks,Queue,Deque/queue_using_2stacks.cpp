#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
	stack <T> s1, s2;
public:
	void push(T x) {
		s1.push(x);
	}

	void pop() {
		if (s1.empty()) {
			return;
		}
		while (s1.size() > 1) {
			T element = s1.top();
			s2.push(element);
			s1.pop();
		}
		s1.pop();
		while (s2.size() >= 1) {
			T element = s2.top();
			s1.push(element);
			s2.pop();
		}
	}

	T front() {
		while (s1.size() > 1) {
			T element = s1.top();
			s2.push(element);
			s1.pop();
		}
		T temp = s1.top();
		while (s2.size() >= 1) {
			T element = s2.top();
			s1.push(element);
			s2.pop();
		}
		return temp;
	}

	int size() {
		return s1.size() + s2.size();
	}

	bool empty() {
		return size() == 0;
	}
};

int main() {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty()) {
		cout << q.front() << " " ;
		q.pop();
	}
	return 0;
}