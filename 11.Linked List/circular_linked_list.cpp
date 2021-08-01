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

void insertAtHead(node* &head, int d) {
	node*n = new node(d);
	node*temp = head;

	n->next = head;
	if (temp != NULL) {
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = n;
	}
	//putting an else condition for self loop when single node is present
	else {
		n->next = n;
	}
	head = n;
}

node* getNode(node*head, int key) {
	node*temp = head;
	//for all nodes except for last node
	while (temp->next != head) {
		if ((temp->data) == key) {
			return temp;
		}
		temp = temp->next;
	}
	//check for last node
	if (temp->data == key) {
		return temp;
	}
	return NULL;
}
//delete any node
void deleteNode(node*&head, int d){
	node* del = getNode(head, d);
	if(del == NULL)
		return;
	//otherwise
	if(head == del){
		head = head->next;
	}

	node*temp = head;
	//stop at prev node of the node to be deleted
	while(temp->next != del){
		temp = temp->next;
	}
	temp->next = del->next;
	delete del;
}

void print(node* head) {
	node*temp = head;
	while (temp->next != head) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << temp->data << endl;
	return;
}

int main() {

	node* head = NULL;
	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	print(head);

	deleteNode(head, 30);

	print(head);
	return 0;
}