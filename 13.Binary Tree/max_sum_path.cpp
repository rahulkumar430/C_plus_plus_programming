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

    if (d == -1) {
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void bfs(node *root) { //isko Prateek Si ne levelOrderPrint bola h
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
            cout << f->data << " ";
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

void levelOrderBuild(node*&root) {
    int d;
    cin >> d;

    root = new node(d);
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* n = q.front();
        q.pop();

        int c1, c2;
        //cout<<"Enter children of "<< n -> data<<endl;
        cin >> c1 >> c2;
        if (c1 != -1) {
            n -> left = new node(c1);
            q.push(n -> left);
        }
        if (c2 != -1) {
            n -> right = new node(c2);
            q.push(n -> right);
        }
    }
}

ostream& operator<<(ostream &os, node*root) {
    bfs(root);
    return os;
}

istream& operator>>(istream&is, node*&root) {
    levelOrderBuild(root);
    return is;
}

class Pair {
public:
    int branchSum;
    int maxSum;

    Pair() {
        branchSum = 0;
        maxSum = 0;
    }
};

Pair maxSumPath(node*root) {
    Pair p;
    if (root == NULL) {
        return p;
    }
    Pair left = maxSumPath(root -> left);
    Pair right = maxSumPath(root -> right);

    //construct two values
    int op1 = root -> data;
    int op2 = left.branchSum + root -> data;
    int op3 = right.branchSum + root -> data;
    int op4 = left.branchSum + right.branchSum + root -> data;

    int current_ans_through_root = max(op1, max(op2, max(op3, op4)));

    //branch sum of the current root
    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root -> data;
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));
    return p;
}

int main() {

    node*root = NULL;

    cin >> root;
    cout << root << endl;

    cout << "Max Sum Path " << maxSumPath(root).maxSum << endl;
    return 0;
}

/*
10
2 10
20 1 -1 -25
-1 -1 -1 -1 3 4
-1 -1 -1 -1
*/