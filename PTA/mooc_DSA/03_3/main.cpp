#include <bits/stdc++.h>

using namespace std;

typedef int ElementType;
typedef struct Node *BinTree;

typedef struct Node {
	ElementType data;
	Node *left;
	Node *right;
} NODE;

BinTree readTree() {
	BinTree last = NULL, tmp, root=NULL, tRight = NULL;
	stack<BinTree> s;
	int N, n;
	string cmd;
	cin >> N;
	N *= 2;
	while (N--) {
		cin >> cmd;
		if (cmd == "Push") {
			cin >> n;
			tmp = new NODE;
			tmp->data = n;
			tmp->left = NULL;
			tmp->right = NULL;
			if (!root) {
				root = tmp;
			}
			if (tRight) {
				tRight->right = tmp;
				tRight = NULL;
			} else if (s.size()) {
				s.top()->left = tmp;
			} 
			s.push(tmp);
		} else {
			tRight = s.top();
			s.pop();
		}
	}
	return root;
}

bool f = false;

void postTrval(BinTree root) {
	if (root) {
		postTrval(root->left);
		postTrval(root->right);
		if (f) cout << ' ';
		f = true;
		cout << root->data;
	} else return;
}

int main () {
	freopen("test.txt", "r", stdin);
	BinTree t = readTree();
	postTrval(t);
	return 0;
}