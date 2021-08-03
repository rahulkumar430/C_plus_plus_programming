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

//assumption both a and b are present in the tree, all keys are unique
node* lca(node*root, int a, int b) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == a or root->data == b) {
		return root;
	}
	//search in left and right subtrees
	node * leftans = lca(root->left, a, b);
	node* rightans = lca(root->right, a, b);

	if (leftans != NULL and rightans != NULL) {
		return root;
	}
	if (leftans != NULL) {
		return leftans;
	}
	return rightans;
}

int main() {
	node *root = buildTree();
	bfs_levelwise(root);
	cout << endl;
	cout << "LCA of 6 and 9 is: " << lca(root, 6, 9)->data << endl;	//2

	return 0;
}
//1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1