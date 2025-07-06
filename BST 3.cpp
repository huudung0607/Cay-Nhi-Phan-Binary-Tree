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
void PostOrder(node* root) {
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
}


int a[10005];
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    node* root = makeRoot(a[0]);
    for (int i = 0; i < n; i++) {
        insert(root, a[i]);
    }
    PostOrder(root);
}
