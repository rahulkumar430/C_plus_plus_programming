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

int length(node* head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

void print(node * head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void deleteHead(node*&head) {
	if (head == NULL) {
		return;
	}
	node*temp = head-> next;
	delete head;
	head = temp;
}

void deleteMiddle(node*&head, int p) {
	if (head == NULL or p == 0) {
		deleteHead(head);
		return;
	}
	else if (p > length(head)) {
		return;
	}
	/*else if (p == length(head)) {
		deleteTail(head);
		return;
	}*/
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

node* getLastNode(node* head)
{
	node *temp = head;
	while (temp->next != nullptr)
		temp = temp->next;

	return temp;
}


bool isOdd(int num)
{
	if (num % 2 != 0)
		return true;
	else
		return false;
}

/*void even_after_odd(node*& head) {
	node* curr = head;
	node* last = getLastNode(head);
	//node* temp = head;
	int k = 0;
	while (curr != last) {
		if (isOdd(curr->data) == false) {
			insertAtTail(head, curr->data);
			last = last->next;
			last->next = NULL;
			deleteMiddle(head, k);
			k++;
			cout << "step if " << k << endl;
			print(head);
		}
		else {
			curr = curr->next;
			k++;
			cout << "step else " << k << endl;
			print(head);
		}
	}
	return;
}*/

void even_after_odd(node *& head)
{
	node *end = head;
	node *prev = NULL;
	node *curr = head;

	/* Get pointer to the last node */
	while (end->next != NULL)
		end = end->next;

	node *new_end = end;

	/* Consider all odd nodes before the first
	even node and move then after end */
	while (curr->data % 2 == 0 && curr != end)
	{
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}

	// 10->8->17->17->15
	/* Do following steps only if
	there is any even node */
	if (curr->data%2 != 0)
	{
		/* Change the head pointer to
		point to first even node */
		head = curr;

		/* now current points to
		the first even node */
		while (curr != end)
		{
			if ( (curr->data) % 2 != 0 )
			{
				prev = curr;
				curr = curr->next;
			}
			else
			{
				/* break the link between
				prev and current */
				prev->next = curr->next;

				/* Make next of curr as NULL */
				curr->next = NULL;

				/* Move curr to end */
				new_end->next = curr;

				/* make curr as new end of list */
				new_end = curr;

				/* Update current pointer to
				next of the moved node */
				curr = prev->next;
			}
		}
	}

	/* We must have prev set before executing
	lines following this statement */
	else prev = curr;

	/* If there are more than 1 odd nodes
	and end of original list is odd then
	move this node to end to maintain
	same order of odd numbers in modified list */
	if (new_end != end && (end->data) % 2 == 0)
	{
		prev->next = end->next;
		end->next = NULL;
		new_end->next = end;
	}
	return;
}

int main() {
	int n ;
	cin >> n;
	node* head = NULL;

	while (n--)
	{
		int data = 0;
		cin >> data;
		insertAtTail(head, data);
	}

	even_after_odd(head);
	print(head);

	return 0;
}