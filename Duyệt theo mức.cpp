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
void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	cout << root->val << " ";
	while (!q.empty()) {
		node* tmp = q.front();
		q.pop();
		if (tmp->left != NULL) {
			q.push(tmp->left);
			cout << tmp->left->val << " ";
		}
		if (tmp->right != NULL) {
			q.push(tmp->right);
			cout << tmp->right->val << " ";
		}
	}
}
int main()
{
	node* root = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; char c;
		cin >> x >> y >> c;
		if (root == NULL) {
			root = new node(x);
			makeRoot(root, x, y, c);
		}
		else {
			insertRoot(root, x, y, c);
		}
	}
	levelOrder(root);
}
