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

void print(node *root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

int height(node* root) {
	if (root == NULL) {
		return 0;
	}
	int ls = height(root->left);
	int rs = height(root->right);
	return max(ls , rs) + 1;
}

void printkthLevel(node * root, int k) {
	if (root == NULL) {
		return ;
	}
	if (k == 1) {
		cout << root->data << " ";
		return ;
	}
	printkthLevel(root->left, k - 1);
	printkthLevel(root->right, k - 1);
	return;
}

void printAllLevel(node* root) {
	int H = height(root);
	for (int i = 1; i <= H; i++)
	{
		printkthLevel(root, i);
		cout << endl;
	}
	return;
}

void printInorder(node *root) {
	if (root == NULL) {
		return;
	}

	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

void printPostorder(node *root) {
	if (root == NULL) {
		return;
	}

	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->data << " ";
}

int count(node*root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + count(root->left) + count(root->right);
}

void bfs(node *root) {
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node* f = q.front();
		cout << f->data << ",";
		q.pop();

		if (f->left) {
			q.push(f->left);
		}
		if (f->right) {
			q.push(f->right);
		}
	}
	return;
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

int diameter(node*root) {
	if (root == NULL) {
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1 + h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	return max(op1, max(op2, op3));
}

class Pair {
public:
	int height;
	int diameter;
};

Pair fastDiameter(node*root) {
	Pair p;
	if (root == NULL) {
		p.diameter = p.height = 0;
		return p;
	}
	//Otherwise
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = max(left.height, right.height) + 1;
	p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
	return p;
}

int replaceSum(node*root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return root->data;
	}
//Recursive Part
	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;
	return temp + root->data;
}

int main() {
	node* root = buildTree();
	/*	print(root);
		cout << endl;
		printInorder(root);
		cout << endl;
		printPostorder(root);
		cout << endl;

		cout << height(root) << endl;
		printkthLevel(root, 3);
		*/
	//printAllLevel(root);
	//cout << count(root) << endl;
	//bfs(root);
	bfs_levelwise(root);
	cout << endl;
	replaceSum(root);
	bfs_levelwise(root);
	//cout << diameter(root) << endl;
	/*Pair p = fastDiameter(root);
	cout << p.height << endl;
	cout << p.diameter << endl;*/

	return 0;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1