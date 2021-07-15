#include <bits/stdc++.h>

using namespace std;

typedef int ElementType;
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
		Nodes[i]->data = i;
		rootFLG[i] = true;
	}
	for (int i=1; i<=N; ++i) {
		scanf("\n%c %c", &l, &r);
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

void levelTrval(BinTree root) {
	queue<BinTree> q;
	if (root)
		q.push(root);
	else
		return;
	BinTree tmp;
	bool flg = false;
	while (q.size()) {
		if (!q.front()->left && !q.front()->right) {
			if (flg)
				cout << ' ' <<q.front()->data;
			else {
				cout <<q.front()->data;
				flg = true;
			}
		}
		if (q.front()->left) q.push(q.front()->left);
		if (q.front()->right) q.push(q.front()->right);
		q.pop();
	}
}

int main () {
	BinTree t = readTree();
	levelTrval(t);
	return 0;
}