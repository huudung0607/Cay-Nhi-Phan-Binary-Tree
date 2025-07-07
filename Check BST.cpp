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

bool check(vector<int> a, int l, int r) {
    if (l <= r) return 1;
    int mx = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] > mx) {
            mx = a[i];
            bool ok = 1;
            for (int j = i + 1; j <= r; j++) {
                if (a[j] < a[r]) {
                    ok = 0; break;
                }
            }
            if (ok) {
                if (check(a, l, i - 1) && check(a, i + 1, r)) {
                    return 1;
                }
            }
        }
    }
}

vector<int> a(10005);
int main() {
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (check(a, 0, n - 1)) {
        cout << "YES";
    }
    else cout << "NO";
}
