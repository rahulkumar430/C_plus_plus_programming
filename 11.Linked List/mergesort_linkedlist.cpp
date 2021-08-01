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

node* take_input() {
	int d;
	cin >> d;

	node* head = NULL;
	while (d != -1) {	//if there is a text file with input you can do -> while(cin>>d) and delete cin>>d inside the loop
		insertAtTail(head, d);
		cin >> d;
	}
	return head;
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

node* mergeSort(node*head){ 
	//base case
	if (head==NULL or head->next== NULL){
		return head;
	} 
	//rec case 
	//1 . Break 
	node* mid = midpoint(head); 
	node*a = head; 
	node*b = mid->next; 
	mid->next = NULL; 
	//2. rec sort he two parts 
	a = mergeSort(a); 
	b = mergeSort(b);
	//3. merge them
	node* c = merge(a,b);
	return c;
}	

int main() {
	node * head = take_input();
	print(head);

	head = mergeSort(head);
	print(head);

	return 0;
}
