#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	node * root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void bfs_levelwise(node *root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* f = q.front();
		if (f == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << f->data << ",";
			q.pop();

			if (f->left) {
				q.push(f->left);
			}
			if (f->right) {
				q.push(f->right);
			}
		}
	}
	return;
}

class HBpair {
public:
	int height;
	bool balance;
};

HBpair isHeightBalanced(node *root) {
	HBpair p;
	if (root == NULL) {
		p.height = 0;
		p.balance = true;
		return p;
	}
	//recursive case
	HBpair left = isHeightBalanced(root->left);
	HBpair right = isHeightBalanced(root-> right);

	p.height = max(left.height, right.height) + 1;

	if (abs(left.height - right.height) <= 1 && left.balance && right.balance) {
		p.balance = true;
	}
	else {
		p.balance = false;
	}
	return p;

}

node* buildTreeFromArray(int *a, int s, int e) {
	//Base Case
	if (s > e) {
		return NULL;
	}
	//Recursive Case
	int mid = (s + e) / 2;
	node* root = new node(a[mid]);
	root->left = buildTreeFromArray(a, s, mid - 1);
	root->right = buildTreeFromArray(a, mid + 1, e);
	return root;
}

int main() {
	/*node* root = buildTree();
	if(isHeightBalanced(root).balance){
		cout << "Balanced" <<endl;
	}
	else{
		cout << "Not balanced" << endl;
	}*/

	int a[ ] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;

	node*root = buildTreeFromArray(a, 0, n - 1);
	bfs_levelwise(root);
	return 0;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1