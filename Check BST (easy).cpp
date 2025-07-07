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

vector<int> a(10005);
int main() {
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
