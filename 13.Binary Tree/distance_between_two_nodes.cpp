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

//finding tho level of a given node from the root node/any given node
int search(node*root, int key, int level) {
	if (root == NULL) {
		return -1;
	}
	if (root->data == key) {
		return level;
	}
	int left = search(root->left, key, level + 1);
	if (left != -1) {
		return left;
	}
	return search(root->right, key, level + 1);
}

//function to find distance btw 2 nodes
int findDistance(node* root, int a, int b) {
	node* lca_node = lca(root, a, b);	//2

	int l1 = search(lca_node, a, 0);
	int l2 = search(lca_node, b, 0);

	return l1 + l2;
}

int main() {
	node *root = buildTree();
	bfs_levelwise(root);
	cout << endl;
	cout << "Distance between 2 node 6 & 9: " << findDistance(root, 6, 9) << endl;	//4
	cout << "Distance between 2 node 4 & 7: " << findDistance(root, 4, 7) << endl;	//1
	return 0;
}
//1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1