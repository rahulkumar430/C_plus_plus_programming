#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;
	node *prev;
	//constructor
	node(int d) {
		data = d;
		next = NULL;
		prev = NULL;
	}
};

int length(node* head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

//passing a pointer by reference
void insertAtHead(node* &head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}

	node *n = new node(d);
	n -> next = head;
	n -> prev = NULL;
	/*if (head != NULL) {
		head->prev = n;
	}
	*/
	head = n;
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
	tail -> next -> prev = tail;
	return;
}

void insertAtMiddle(node* &head, int d, int p) {
	//corner case
	if (head == NULL or p == 0) {
		insertAtHead(head, d);
	}
	else if (p > length(head)) {
		insertAtTail(head, d);
	}
	else {
		//take p-1 jumps
		int jump = 1;
		node* temp = head;
		while (jump <= p - 1) {
			temp = temp -> next;
			jump++;
		}

		//create a new node
		node* n = new node(d);
		n -> next = temp -> next;
		//temp->next->prev = n;
		temp -> next = n;
		n->prev = temp;
		if (n->next != NULL) {
			n->next->prev = n;
		}
	}

}

void deleteHead(node*&head) {
	if (head == NULL) {
		return;
	}
	node*temp = head-> next;
	delete head;
	head = temp;
	temp->prev = NULL;
}

void deleteTail(node*&head) {
	if (head == NULL) {
		return;
	}
	if (head->next == NULL) {
		delete head;
		return;
	}
	node*second_last = head;
	while ((second_last -> next -> next) != NULL) {
		second_last = second_last -> next;
	}

	delete(second_last -> next);
	second_last -> next = NULL;
	return;
}

void deleteMiddle(node*&head, int p) {
	if (head == NULL or p == 0) {
		deleteHead(head);
		return;
	}
	else if (p > length(head)) {
		return;
	}
	else if (p == length(head)) {
		deleteTail(head);
		return;
	}
	else {
		int jump = 1;
		node*temp = head;
		while (jump <= p - 1) {
			temp = temp -> next;
			jump++;
		}
		node*curr = temp->next;
		temp -> next = curr-> next;
		curr->next->prev = temp;
		delete(curr);
		return;
	}
}

//passing a pointer by value
void print(node* head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	node* head = NULL;
	insertAtHead(head, 5);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtHead(head, 0);
	insertAtMiddle(head, 4 , 3);
	insertAtTail(head, 6);
	print(head);
	//deleteHead(head);
	//print(head);
	//deleteTail(head);
	//print(head);
	deleteMiddle(head, 3);
	print(head);

	return 0;
}