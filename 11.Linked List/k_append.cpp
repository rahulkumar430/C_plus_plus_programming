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

void k_append(node*& head, int k) {
  	node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for (int i = 0; i < k && fast->next != NULL; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    head = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
}

void print(node * head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	int n, k ;
	cin >> n;
	node* head = NULL;
	int temp = n;
	while (temp--)
	{
		int data = 0;
		cin >> data;
		insertAtTail(head, data);
	}
	cin >> k;
	k = k % n;
    if (k == 0)
    {
        print(head);
    }
    else
    {
        head = k_append(head, k);
        print(head);
    }

	return 0;
}