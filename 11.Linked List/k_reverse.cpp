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

node* reverse(node* head, int k) {
	int x = k;
	node* C = head;
	node* P = NULL;
	node* N = NULL;
	while (C != NULL && x > 0) {
		N = C-> next;
		C-> next = P;
		P = C;
		C = N;
		x--;
	}
	if(C != NULL){
		head->next = reverse(N, k);
	}
	return P;
}

void print(node * head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	int n , k;
	cin >> n >> k;
	node* head = NULL;

	while (n--)
	{
		int data = 0;
		cin >> data;
		insertAtTail(head, data);
	}
	head = reverse(head, k);
	print(head);

	return 0;
}