#include <bits/stdc++.h>

using namespace std;

typedef char ElementType;
typedef struct Node *BinTree;

typedef struct Node {
	ElementType data;
	Node *left;
	Node *right;
} NODE;

inline void setSubTree(char side, BinTree &tar, BinTree nodes[],bool FLG[]) {
		if (side != '-') {
			tar = nodes[side-'0'];
			FLG[side-'0'] = false;
		} else tar = NULL;
}


BinTree readTree() {
	BinTree res = NULL;
	int N;
	char l, r;
	scanf("%d", &N);
	bool rootFLG[N];
	BinTree Nodes[N];
	for (int i=0; i<N; ++i) {
		Nodes[i] = new NODE;
		rootFLG[i] = true;
	}
	for (int i=1; i<=N; ++i) {
		scanf("\n%c %c %c", &(Nodes[i-1]->data), &l, &r);
		setSubTree(l, Nodes[i-1]->left, Nodes, rootFLG);
		setSubTree(r, Nodes[i-1]->right, Nodes, rootFLG);
	}
	for (int i=0; i<N; ++i) {
		if (rootFLG[i]) {
			res = Nodes[i];
			return res;
		}
	}
	return res;
}

void preTrval(BinTree root) {
	if (root) {
		cout << root->data << ' ';
		preTrval(root->left);
		preTrval(root->right);
	} else {
		return;
	}
}

bool isSame(BinTree t1, BinTree t2) {
	if (!t1 && !t2) {
		return true;
	} else if (t1 && t2) {
		return t1->data == t2->data;
	} else {
		return false;
	}
}

bool canRecons(BinTree t1, BinTree t2) {
	if (!t1 && !t2) return true;
	if (isSame(t1->left, t2->left) && isSame(t1->right, t2->right)) {
		return canRecons(t1->left, t2->left) && canRecons(t1->right, t2->right);
	} else if(isSame(t1->left, t2->right) && isSame(t1->right, t2->left)) {
		return canRecons(t1->left, t2->right) && canRecons(t1->right, t2->left);
	} else {
		return false;
	}
}


int main () {
	BinTree t1 = readTree();
	BinTree t2 = readTree();
	if (t1 && t2) {
		if (canRecons(t1, t2)) {
			cout << "Yes";
		} else {
			cout << "No";
		}
	} else if (!t1 && !t2) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}