#include <bits/stdc++.h>

using namespace std;

typedef struct NODE* AVLtree;
typedef struct NODE Node;


struct NODE {
	int Data;
	NODE *Left;
	NODE *Right;
	int Height;
};

int Max(int a, int b) {
	return a>b?a:b;
}

AVLtree NewNode(int X) {
	AVLtree tmp = new Node;
	tmp->Data = X;
	tmp->Left = NULL;
	tmp->Right = NULL;
	tmp->Height = 1;
	return tmp;
}

int getHeight(AVLtree root) {
	if (!root) {
		return 0;
	} else {
		return root->Height;
	}
}

void updateHeight(AVLtree root) {
	if (!root) return;
	root->Height = Max(getHeight(root->Left), getHeight(root->Right)) + 1;
}

AVLtree LLrotation(AVLtree root) {
	AVLtree newRoot = root->Left;
	root->Left = root->Left->Right;
	newRoot->Right = root;
	updateHeight(root);
	updateHeight(newRoot);
	return newRoot;
}
AVLtree RRrotation(AVLtree root) {
	AVLtree newRoot = root->Right;
	root->Right = root->Right->Left;
	newRoot->Left = root;
	updateHeight(root);
	updateHeight(newRoot);
	return newRoot;
}
AVLtree LRrotation(AVLtree root) {
	AVLtree newRoot = root->Left->Right;
	AVLtree tmpL = newRoot->Left;
	AVLtree tmpR = newRoot->Right;
	root->Left->Right = tmpL;
	newRoot->Left = root->Left;
	newRoot->Right = root;
	root->Left = tmpR;
	updateHeight(newRoot->Left);
	updateHeight(newRoot->Right);
	updateHeight(newRoot);
	return newRoot;
}
AVLtree RLrotation(AVLtree root) {
	AVLtree newRoot = root->Right->Left;
	AVLtree tmpR = newRoot->Right;
	AVLtree tmpL = newRoot->Left;
	root->Right->Left = tmpR;
	newRoot->Right = root->Right;
	newRoot->Left = root;
	root->Right = tmpL;
	updateHeight(newRoot->Left);
	updateHeight(newRoot->Right);
	updateHeight(newRoot);
	return newRoot;
}

AVLtree Insert(AVLtree root, int X) {
	if (!root) {
		return NewNode(X);
	} else if (X < root->Data) {
		root->Left = Insert(root->Left, X);
		if (getHeight(root->Left) - getHeight(root->Right) == 2) {
			if (X < root->Left->Data) {
				root = LLrotation(root);
			} else if (X > root->Left->Data) {
				root = LRrotation(root);
			}
		}
	} else if (X > root->Data) {
		root->Right = Insert(root->Right, X);
		if (getHeight(root->Right) - getHeight(root->Left) == 2) {
			if (X < root->Right->Data) {
				root = RLrotation(root);
			} else if (X > root->Right->Data) {
				root = RRrotation(root);
			}
		}
	}
	updateHeight(root);
	return root;
}

int main () {
	int N, tmp;
	AVLtree root;
	root = NULL;
	cin >> N;
	while (N--) {
		cin >> tmp;
		root = Insert(root, tmp);
	}
	if (root) {
		cout << root->Data;
	}
	return 0;
}