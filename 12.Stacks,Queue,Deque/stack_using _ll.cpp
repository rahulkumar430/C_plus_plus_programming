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

//passing a pointer by reference
void push(node* &head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}

	node *n = new node(d);
	n -> next = head;	// (*n).next = head;
	head = n;
}

void print(node* head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

void pop(node*&head) {
	if (head == NULL) {
		return;
	}
	node*temp = head-> next;
	delete head;
	head = temp;
}

void top(node*head) {
	if (head == NULL) {
		cout << "Empty stack!" << endl;
	}
	else {
		cout << head->data << endl;
	}
}

int main() {
	node* head = NULL;
	push(head, 5);
	push(head, 2);
	push(head, 1);
	push(head, 0);

	print(head);

	pop(head);
	print(head);

	top(head);

	return 0;
}