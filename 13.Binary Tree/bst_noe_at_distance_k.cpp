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

void printkthLevel(node * root, int k) {
	if (root == NULL) {
		return ;
	}
	if (k == 0) {
		cout << root->data << " ";
		return ;
	}
	printkthLevel(root->left, k - 1);
	printkthLevel(root->right, k - 1);
	return;
}

int printAtDistanceK(node *root, node* target, int k) {
	//base case
	if (root == NULL)
		return -1;

	//reach the target node
	if (root == target) {
		printkthLevel(target, k);
		return 0;
	}

	//go to ancestor
	int DL = printAtDistanceK(root -> left, target, k);

	if (DL != -1) {
		//Again there are 2 cases
		// Ancestor itself or you need go to the right
		if (DL + 1 == k) {
			cout << root-> data << " ";
		}
		else {
			printkthLevel(root->right, k - 2 - DL);
		}

		return 1 + DL;
	}

	int DR = printAtDistanceK(root -> right, target, k);

	if (DR != -1) {
		//Again there are 2 cases
		// Ancestor itself or you need go to the left
		if (DR + 1 == k) {
			cout << root-> data << " ";
		}
		else {
			printkthLevel(root->left, k - 2 - DR);
		}

		return 1 + DR;
	}
	//node is not present in left or right substree
	return -1;
}

int main() {
	node *root = buildTree();

	node* target = root->left->left;

	//print the tree
	bfs_levelwise(root);

	//int k;
	//cin >> k;
	//hardcoded k value
	printAtDistanceK(root, target, 2); // 10 11 5 1
	printAtDistanceK(root, target, 3); // 8 9 3
}
//1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1