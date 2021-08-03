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

void printRightView(node *root, int level, int &maxlevel) {
	if (root == NULL)
		return;

	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}
	//root -> right -> left
	printRightView(root->right, level + 1 , maxlevel);
	printRightView(root->left, level + 1, maxlevel);

}

int main() {
	node* root = buildTree();
	bfs_levelwise(root);
	cout << endl;
	int maxlevel = -1;
	printRightView(root, 0 , maxlevel);

	return 0;
}
// 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1