
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
	int height;
};

node* makeRoot(int x) {
	node* newNode = new node;
	newNode->data = x;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

int treeHeight(node* root) {
	if (root == NULL) return 0;
	return root->height;
}

int getBalance(node* root) {
	if (root == NULL) return 0;
	return treeHeight(root->left) - treeHeight(root->right);
}

node* rightRotation(node* y) {
	node* x = y->left;
	node* T2 = x->right;
	//Rotation
	x->right = y;
	y->left = T2;

	x->height = max(treeHeight(x->left), treeHeight(x->right)) + 1;
	y->height = max(treeHeight(y->left), treeHeight(y->right)) + 1;
	return x;
}

node* leftRotation(node* x) {
	node* y = x->right;
	node* T2 = y->left;
	//Rotation
	y->left = x;
	x->right = T2;

	x->height = max(treeHeight(x->left), treeHeight(x->right)) + 1;
	y->height = max(treeHeight(y->left), treeHeight(y->right)) + 1;
	return y;
}

node* insertRoot(node* root,int x) {
	if (root == NULL) {
		return makeRoot(x);
	}
	if (x < root->data) {
		root->left = insertRoot(root->left, x);
	}
	else if (x > root->data) {
		root->right = insertRoot(root->right, x);
	}
	else return root;
	root->height = max(treeHeight(root->left), treeHeight(root->right)) + 1;
	int balance = getBalance(root);
	//Rotation
	//left left
	/*		30 <-- root
		   /   
		  20  <-- root->left->data
         /
	    10  <-- x                         */
	if (balance > 1 && x < root->left->data) {
		return rightRotation(root);
	}
	//right right
	/*		30 <-- root
			  \
			   20 <-- root->right->data
				 \
				  10 <-- x     */
	if (balance < -1 && x > root->right->data) {
		return leftRotation(root);
	}

	//left right
	/*		30  <-- root
		   /
		  20  <-- root->left->data
			\
			 25   <-- x      */
	if (balance > 1 && x > root->left->data) {
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	//right left
	/*		30  <-- root
			  \
			   40  <-- root->right->data
			  /
		     35  <-- x    */
	if (balance < -1 && x > root->right->data) {
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}

node* minValueNode(node* root) {
	node* tmp = root;
	while (tmp != NULL && tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp;
}

node* deleteNode(node* root,int x) {
	if (root == NULL) return root;
	if (x < root->data) {
		root->left = deleteNode(root->left, x);
	}
	else if (x > root->data) {
		root->right = deleteNode(root->right, x);
	}
	else {
		if (root->left == NULL) {
			node* tmp = root->right;
			delete root;
			return tmp;
		}
		else if (root->right == NULL) {
			node* tmp = root->left;
			delete root;
			return tmp;
		}
		else {
			node* tmp = minValueNode(root->right);
			root->data = tmp->data;
			root->right = deleteNode(root->right, tmp->data);
		}
	}
	int balance = getBalance(root);
	root->height = max(treeHeight(root->left), treeHeight(root->right)) + 1;
	//Rotation
	//x la node them, root la dinh cua cay
	//left left
	/*		30 <-- root
		   /
		  20  <-- root->left->data
		 /
		10  <-- x                         */
	if (balance > 1 && getBalance(root->left) >= 0) {
		return rightRotation(root);
	}
	//right right
	/*		30 <-- root
			  \
			   20 <-- root->right->data
				 \
				  10 <-- x     */
	if (balance < -1 && getBalance(root->right) <= 0) {
		return leftRotation(root);
	}

	//left right
	/*		30  <-- root
		   /
		  20  <-- root->left->data
			\
			 25   <-- x      */
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	//right left
	/*		30  <-- root
			  \
			   40  <-- root->right->data
			  /
			 35  <-- x    */
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}

void inOrder(node* root) {
	if (root == NULL) return;	
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

int main()
{
	node* root = NULL;
	root = insertRoot(root, 30);
	root = insertRoot(root, 20);
	root = insertRoot(root, 40);
	root = insertRoot(root, 10);
	root = insertRoot(root, 25);
	root = insertRoot(root, 50);
	root = insertRoot(root, 5);
	inOrder(root);
	cout << endl;
	root = deleteNode(root, 20);
	inOrder(root);
}

