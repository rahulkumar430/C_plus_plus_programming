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
void insertAtHead(node* &head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}

	node *n = new node(d);
	n -> next = head;	// (*n).next = head;
	head = n;
}

int length(node* head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}
//passing a pointer by value
void print(node* head) {
	while (head != NULL) {
		cout << head->data << " -> ";
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
		temp -> next = n;
	}

}

void deleteHead(node*&head) {
	if (head == NULL) {
		return;
	}
	node*temp = head-> next;
	delete head;
	head = temp;
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
		node*prev = head;
		while (jump <= p - 1) {
			prev = prev -> next;
			jump++;
		}
		node*curr = prev->next;
		prev -> next = curr-> next;
		delete(curr);
		return;
	}
}

//linear search by iteration
bool search(node*head, int key) {
	node*temp = head;
	while (temp != NULL) {
		if ((head->data) == key) {
			return true;
		}
		head = head->next;
	}
	return false;
}

//recursively
bool recursive_search(node*head, int key) {
	if (head == NULL) {
		return false;
	}
	if ((head->data) == key) {
		return true;
	}
	else {
		return recursive_search(head->next , key);
	}
}

node* take_input() {
	int d;
	cin >> d;

	node* head = NULL;
	while (d != -1) {	//if there is a text file with input you can do -> while(cin>>d) and delete cin>>d inside the loop
		insertAtHead(head, d);
		cin >> d;
	}
	return head;
}

istream& operator>>(istream &is, node*&head) {
	head = take_input();
	return is;
}

ostream& operator<<(ostream &os, node*head) {
	print(head);
	return os;
}

//Reverse linked list
void reverse(node*& head) {
	node* C = head;
	node* P = NULL;
	node* N;
	while (C != NULL) {
		//save the next node location by a next pointer
		N = C-> next;
		//make current pointer points to the previous one
		C-> next = P;
		//update P anc C take them 1 step forward
		P = C;
		C = N;
	}
	head = P;
}

node* recursive_Reverse(node * head) {
	//smallest linked list
	if (head->next == NULL or head == NULL) {
		return head;
	}
	//rec case
	node *smallhead = recursive_Reverse(head->next);
	//O(N^2) complexity if we keep iterating to get the temp
	/*node* temp = smallhead;
	while (temp -> next != NULL) {
		temp = temp->next;
	}
	head -> next = NULL;
	temp -> next = head;*/

	/*node* temp = head->next;
	temp->next = head;*/ // instead of creating a temp node we can do like
	head-> next -> next = head;
	head->next = NULL;
	return smallhead;
}
//find midpoint by runners technique
node* midpoint(node*head) {
	if (head->next == NULL or head == NULL) {
		return head;
	}
	node* slow = head;
	node* fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//find Kth node by runners technique
node* kthpoint(node* head, int k) {
	node * slow = head;
	node * fast = head;
	while (k--)
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}


int main() {
	//node * head;
	//node * head2;
	//node * head = take_input();
	//node * head2 = take_input();
	//print(head);
	//reverse(head);
	//head = recursive_Reverse(head);
	//print(head);
	//cin >> head >> head2;
	//cout << head << head2;

	//node* mid = midpoint(head);
	//cout << mid->data << endl;

	/*int k;
	cin >> k;
	node* element = kthpoint(head, k);
	cout << element->data << endl;*/

	node* head = NULL;
	insertAtHead(head, 5);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtHead(head, 0);

	insertAtMiddle(head, 4 , 3);
	insertAtTail(head, 6);

	//deleteHead(head);

	print(head);

	//deleteTail(head);

	deleteMiddle(head, 3);

	print(head);

	/*int key;
	cin >> key;

	if (search(head, key)) {
		cout << "Element Found" << endl;
	}
	else {
		cout << "Element Not Found" << endl;
	}

	if (recursive_search(head, key)) {
		cout << "Element Found" << endl;
	}
	else {
		cout << "Element Not Found" << endl;
	}*/

	return 0;
}