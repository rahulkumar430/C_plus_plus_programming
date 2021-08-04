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

//Accepts the old root node & data and returns the new root node
node* insertInBST(node *root, int data) {
    //Base Case
    if (root == NULL) {
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if (data <= root->data) {
        root->left = insertInBST(root->left, data);
    }
    else {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node* buildFromPre(int pre[], int size) {

    node*root = NULL;

    for(int i = 0; i < size; i++) {
        root = insertInBST(root, pre[i]);
    }
    return root;
}
//Print the BST Level By Level
void bfs(node *root) {
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
//Inorder Print
void inorder(node*root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}

int main() {

    int pre[] = {5, 3, 1, 7, 6, 8};
    int size = sizeof(pre) / sizeof(pre[0]);
    node*root = buildFromPre(pre,size);
    inorder(root);
    cout << endl;
    bfs(root);

    return 0;
}

//5 3 1 7 6 8 - pre
//1 3 5 6 7 8 - in