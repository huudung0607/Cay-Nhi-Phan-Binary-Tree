
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
	int data;
	node* left;
	node* right;
};

node* makeRoot(int x) {
	node* newRoot = new node;
	newRoot->data = x;
	newRoot->left = NULL;
	newRoot->right = NULL;
	return newRoot;
}

void makeRoot(node* root, int v, int c) {
	if (root == NULL) return;
	if (c == 'L') root->left = makeRoot(v);
	else root->right = makeRoot(v);
}
//u = goc, v = la, c = ki tu L & R, L = la trai, R = la phai
void insertLeaf(node*& root, int u, int v, int c) {
	if (root == NULL) return;
	if (root->data == u) {
		makeRoot(root, v, c);
	}
	else {
		insertLeaf(root->left, u, v, c);
		insertLeaf(root->right, u, v, c);
	}
}

void PreOrder(node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

int height = 0;
void dem(node* root) {
	if (root->left == NULL && root->right == NULL) {
		height++;
		return;
	}
	height++;
	dem(root->left);
	dem(root->right);
}

int main()
{
	node* root = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		if (root == NULL) {
			root = makeRoot(u);
			insertLeaf(root, u, v, c);
		}
		else {
			insertLeaf(root, u, v, c);
		}
	}
	PreOrder(root);
	cout << endl;
	dem(root);
	cout << height;
}

