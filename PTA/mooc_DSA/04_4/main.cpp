#include <bits/stdc++.h>

using namespace std;

typedef int ElementType;
typedef struct Node *BinTree;

typedef struct Node {
	ElementType data;
	Node *left;
	Node *right;
} NODE;

void insertBT(BinTree root, int a) {
	while (root) {
		if (a < root->data) {
			if (root->left) 
				root = root->left;
			else {
				root->left = new NODE;
				root->left->data = a;
				root->left->left = NULL;
				root->left->right = NULL;
				return;
			}

		} else if (a > root->data) {
			if (root->right) 
				root = root->right;
			else {
				root->right = new NODE;
				root->right->data = a;
				root->right->left = NULL;
				root->right->right = NULL;
				return;
			}
		} else {
			return;
		}
	}
}

BinTree readTree(int len) {
	int tmp;
	BinTree root, tmp;
	while (len--) {
		cin >> tmp;
		if (root) {
			insertBT(root, tmp);
		} else {
			root = new NODE;
			root->data = tmp;
			root->left = NULL;
			root->right = NULL;
		}
		
	}
}

int main () {
	return 0;
}