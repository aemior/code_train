#include <bits/stdc++.h>

using namespace std;

typedef int ElementType;
typedef struct Node *BinTree;

typedef struct Node {
	ElementType data;
	Node *left;
	Node *right;
} NODE;


inline void newNODE(BinTree &tar, ElementType &d) {
	tar = new NODE;
	tar->data = d;
	tar->left = NULL;
	tar->right = NULL;
}

void insertBT(BinTree &root, int &a) {
	if (root) {
		if (a < root->data) insertBT(root->left, a);
		else if (a > root->data) insertBT(root->right, a);
		else return;
	} else {
		newNODE(root, a);
	}
	return;
}

BinTree readTree(int len) {
	int tmp;
	BinTree root=NULL;
	while (len--) {
		cin >> tmp;
		if (root) {
			insertBT(root, tmp);
		} else {
			newNODE(root, tmp);
		}
	}
	return root;
}

bool cmpTree(BinTree t1, BinTree t2) {
	if (t1 && t2) {
		return t1->data == t2->data &&
		       cmpTree(t1->left, t2->left) &&
			   cmpTree(t1->right, t2->right);
	} else if (!t1 && !t2) {
		return true;
	} else {
		return false;
	}
}

void delTree(BinTree root) {
	if (root) {
		delTree(root->left);
		delTree(root->right);
		delete root;
	} else return;
}

int main () {
	freopen("test.txt", "r", stdin);
	while (cin.peek() != '0') {
		int L, N;
		cin >> L >> N;
		if (cin.peek() == '\n') cin.get();
		BinTree base = readTree(L);
		if (cin.peek() == '\n') cin.get();
		while (N--) {
			BinTree test = readTree(L);
			if (cmpTree(base, test)) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
			delTree(test);
			if (cin.peek() == '\n') cin.get();
		}
	}
	return 0;
}