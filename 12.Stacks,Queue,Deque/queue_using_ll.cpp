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
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

void push(node*&head, int d) {
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

void pop(node*&head) {
	if (head == NULL) {
		return;
	}
	node*temp = head-> next;
	delete head;
	head = temp;
}

int main(){
	node* head = NULL;
	push(head, 1);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	push(head, 5);

	print(head);

	pop(head);
	pop(head);

	print(head);
	
	return 0;
}