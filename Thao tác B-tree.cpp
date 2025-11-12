
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
	int n;//so khoa
	int m;//bac cua cay
	int* keys;//mang chua cac khoa
	bool leaf;//co phai la hay ko
	node** children;//node con
};

node* makeNode(int m, bool leaf) {
	node* newNode = new node;
	newNode->m = m;
	newNode->leaf = leaf;
	newNode->keys = new int[m - 1];
	newNode->children = new node * [m];
	newNode->n = 0;
	for (int i = 0; i < m; i++) {
		newNode->children[i] == NULL; 
	}
	return newNode;
}

void Traversal(node *root) {
	if (root == NULL) return;
	int i;
	for (i = 0; i < root->n; i++) {
		if (!root->leaf) {
			Traversal(root->children[i]);
		}
		cout << root->keys[i] << " ";
	}
	if (!root->leaf) {
		Traversal(root->children[i]);
	}
}	
node* search(node* root,int x) {
	int i = 0;
	while (i < root->n && x > root->keys[i]) {
		i++;
	}
	if (i < root->n && root->keys[i] == x) {
		return root;
	}
	if (root->leaf) return NULL;
	return search(root->children[i], x);
}

void splitChild(node* x, int i, node* y) {
	int m = y->m;
	node* z = makeNode(m, y->leaf);
	z->n = m / 2 - 1;
	for (int j = 0; j < m / 2 - 1; j++) {
		z->keys[j] = y->keys[j + m / 2];
	}
	if (!y->leaf) {
		for (int j = 0; j < m / 2; j++) {
			z->children[j] = y->children[j + m / 2];
		}
	}
	y->n = m / 2 - 1;
	for (int j = x->n; j >= i + 1; j--) {
		x->children[j + 1] = x->children[j];
	}
	x->children[i + 1] = z;
	for (int j = x->n - 1; j >= i; j--) {
	x->keys[j + 1] = x->keys[j];
	}
	x->keys[i] = y->keys[m / 2 - 1];
	x->n++;
}
void insertNonFull(node* root, int x) {
	int i = root->n - 1;

	if (root->leaf) {
		while (i >= 0 && x < root->keys[i]) {
			root->keys[i + 1] = root->keys[i];
			i--;
		}
		root->keys[i + 1] = x;
		root->n++;
	}
	else {
		while (i >= 0 && x < root->keys[i]) i--;

		if (root->children[i + 1]->n == root->m - 1) {
			splitChild(root, i + 1, root->children[i + 1]);
			if (x > root->keys[i + 1]) i++;
		}
		insertNonFull(root->children[i + 1], x);
	}
}
void insertRoot(node*& root, int x) {
	if (root == NULL) {
		root = makeNode(5, true); //vd cay bac 5
		root->keys[0] = x;
		root->n = 1;
		return;
	}

	if (root->n == root->m - 1) {
		node* s = makeNode(root->m, false);
		s->children[0] = root;
		splitChild(s, 0, root);

		int i = 0;
		if (x > s->keys[0]) i++;
		insertNonFull(s->children[i],x);
		root = s;
	}
	else {
		insertNonFull(root,x);
	}
}

int main()
{
		node* root = NULL;
		int m = 5; 
		int a[] = { 10, 20, 5, 6, 12, 30, 7, 17 };
		for (int x : a) insertRoot(root, x);

		cout << "Cay B (duyet theo thu tu tang dan): ";
		Traversal(root);
		cout << endl;

		int k = 12;
		if (search(root, k) != NULL)
			cout << "Tim thay " << k << " trong cay\n";
		else
			cout << "Khong tim thay " << k << " trong cay\n";

		return 0;

}

