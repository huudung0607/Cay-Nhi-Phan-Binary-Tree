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
bool check(node* root1, node* root2) {
	if (root1 == NULL && root2 == NULL) return true;
	if (root1 == NULL || root2 == NULL) return false;
	if (root1->val != root2->val) return false;
	return check(root1->left, root2->left) && check(root1->right, root2->right);
}
int main() {
	int n; cin >> n;
	node* root1 = NULL;
	node* root2 = NULL;
	for (int i = 0; i < n; i++) {
		int u, v; char c;
		cin >> u >> v >> c;
		if (root1 == NULL) {
			root1 = new node(u);
			makeRoot(root1, u, v, c);
		}
		else {
			insertRoot(root1, u, v, c);
		}
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v; char c; cin >> u >> v >> c;
		if (root2 == NULL) {
			root2 = new node(u);
			makeRoot(root2, u, v, c);
		}
		else {
			insertRoot(root2, u, v, c);
		}
	}
	if (check(root1, root2)) {
		cout << "YES";
	}
	else cout << "NO";
}
