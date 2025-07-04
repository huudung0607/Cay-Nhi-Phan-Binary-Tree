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

int height = 0;
bool heightCheck(node* root, int h) {
	if (root == NULL) return true;
	if (root->left == NULL && root->right == NULL) {
		if (height == 0) {
			height = h;
		}
		else if (h != height) {
			return false;
		}
	}
	return heightCheck(root->left, h + 1) && 
		heightCheck(root->right, h + 1);
}
bool checkRoot(node* root) {
	if (root == NULL) return true;
	if (root->left == NULL && root->right == NULL) return true;
	if (root->left == NULL && root->right != NULL) return false;
	if (root->right == NULL && root->left != NULL) return false;
	return checkRoot(root->left) && checkRoot(root->right);
}
int findRoot(int root, vector<int> in, int n) {
	for (int i = 0; i < n; i++) {
		if (in[i] == root) {
			return i;
		}
	}
	return -1;
}
void postOrder(vector<int> pre,vector<int> in,int n) {
	if (n == 0) return;
	int root = pre[0];
	int rootidx = findRoot(root, in, n);
	vector<int> leftPre = vector<int>(pre.begin() + 1, pre.begin() + rootidx + 1);
	vector<int> rightPre = vector<int>(pre.begin() + rootidx + 1, pre.end());

	vector<int> leftIn = vector<int>(in.begin(), in.begin() + rootidx);
	vector<int> rightIn = vector<int>(in.begin() + rootidx + 1, in.end());
	postOrder(leftPre, leftIn, leftPre.size());
	postOrder(rightPre, rightIn, rightPre.size());
	cout << root << " ";
}

int main()
{
	int n;
	cin >> n;
	vector<int> pre(n), in(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	postOrder(pre, in, n);
}
