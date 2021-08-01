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


void removeCycle(node* head, node* loop_node) {
	node* node1 = loop_node;
	node* node2 = loop_node;
	int k = 1;
	while (node1->next != node2) {
		node1 = node1->next;
		k++;
	}
	/*
	node1 = head;
	node2 = head;

	for (int i = 0; i < k; i++)
	{
		node2 = node2->next;
	}

	while (node2 != node1) {
		node1 = node1->next;
		node2 = node2->next;
	}
	while (node2->next != node1) {
		node2 = node2->next;
	}
	node2->next = NULL;
	*/

	node1 = head;
	node2 = loop_node;

	while (node2 != node1) {
		node1 = node1->next;
		node2 = node2->next;
	}
	//reach upto previous node where loop starts then make it to point at null
	while (--k) {
		node2 = node2->next;
	}
	node2->next = NULL;
}

bool detectCycle(node* head) {
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	node * slow = head;
	node * fast = head;

	while (fast != NULL and fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {
			removeCycle(head, slow);
			return true;
		}
	}
	return false;
}

int main() {
	node * head = take_input();

	// Create a loop for testing
	head->next->next->next->next->next->next->next = head->next->next;

	if (detectCycle(head))
		cout << "Cycle found" << endl;
	else
		cout << "No Cycle" << endl;

	print(head);

	return 0;
}
