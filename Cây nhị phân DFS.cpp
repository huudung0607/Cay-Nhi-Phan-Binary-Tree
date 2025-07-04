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
void insertRoot(node* root, int u, int v, char c) {
	if (root == NULL)return;
	if (root->val == u) {
		makeRoot(root, u, v, c);
	}
	else {
		insertRoot(root->left, u, v, c);
		insertRoot(root->right, u, v, c);
	}
}
void dfs(node* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	dfs(root->right);
	dfs(root->left);
}
int main() {
	int n; cin >> n;
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		int u, v; char c;
		cin >> u >> v >> c;
		if (root == NULL) {
			root = new node(u);
			makeRoot(root, u, v, c);
		}
		else {
			insertRoot(root, u, v, c);
		}
	}
	dfs(root);
}
