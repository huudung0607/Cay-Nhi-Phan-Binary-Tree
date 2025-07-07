#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};
node* makeRoot(int n) {
    node* newRoot = new node;
    newRoot->val = n;
    newRoot->left = NULL;
    newRoot->right = NULL;
    return newRoot;
}
node* insert(node* root, int key) {
    if (root == NULL) {
        return makeRoot(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    }
    else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}
node* minNode(node* root) {
    node* tmp = root;
    while (tmp != NULL && tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

node* deleteNode(node* root, int key) {
    if (root == NULL) return root;
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == NULL) {
            node* tmp = root->left;
            delete root;
            return tmp;
        }
        else {
            node* tmp = minNode(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right, tmp->val);
        }
    }
    return root;
}
void InOrder(node* root) {
    if (root == NULL) return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}
int a[10005];
int main() {
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    node* root = makeRoot(a[0]);
    for (int i = 1; i < n; i++) {
        insert(root, a[i]);
    }
    root = deleteNode(root, x);
    InOrder(root);
}
