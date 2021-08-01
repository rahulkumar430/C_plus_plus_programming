#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;
	//constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};

void print(node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void insertAtTail(node*&head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}

	node*tail = head;
	while (tail -> next != NULL) {
		tail = tail -> next;
	}
	tail -> next = new node(d);
	return;
}

void take_input(node*&head, int n ) {
	while (n--)
	{
		int data = 0;
		cin >> data;
		insertAtTail(head, data);
	}
}

//merge two sorted linked list
node* merge(node *a, node *b) {
	//base case
	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}

	//take a head pointer
	node*c;
	if (a-> data < b-> data) {
		c = a;
		c->next = merge(a->next, b);
	}
	else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int m;
		cin >> m;
		node * head = NULL;
		take_input(head, m);
		int n;
		cin >> n;
		node * head2 = NULL;
		take_input(head2, n);
		//print(head);
		//print(head2);

		node* newHead = merge(head, head2);
		print(newHead);
	}
	return 0;
}
