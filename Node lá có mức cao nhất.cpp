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
    node(int x) {
        val = x;
        left = right = NULL;
    }
};

void makeRoot(node* root, int u, int v, char c) {
    if (c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node* root, int u, int v, char c) {
    if (root == NULL) return;
    if (root->val == u) {
        makeRoot(root, u, v, c);
    }
    else {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}
int d[100005];
vector<int> v;
void dem(node* root,int h) {
    if (root == NULL) {
        return;
    }
    d[root->val] = h;
    v.push_back(d[root->val]);
    dem(root->left, h + 1);
    dem(root->right, h + 1);
}

int main() {
    node* root = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        if (root == NULL) {
            root = new node(u);
            makeRoot(root, u, v, c);
        }
        else {
            insertNode(root, u, v, c);
        }
    }
    dem(root,0);
    int maxval = 0;
    for (auto x : v) {
        maxval = max(maxval, x);
    }
    int dem = 0;
    for (auto x : v) {
        if (x == maxval) {
            dem++;
        }
    }
    cout << dem;
}
