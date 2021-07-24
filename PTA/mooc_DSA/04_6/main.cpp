#include <bits/stdc++.h>

using namespace std;

void outPut(int *tree, int size, bool nl=true) {
	bool flg = false;
	for (int i=0; i<size; ++i) {
		if (flg) cout << ' ';
		else flg = true;
		cout << *(tree+i);
	}
	if (nl)
		cout << endl;
}

int fullNum(int level) {
	if (level > 0) {
		int res = 1;
		int levelN = 1;
		for (int i=1; i<level; ++i) {
			res = res + levelN * 2;
			levelN *= 2; 
		}
		return res;
	}
	return 0;
}

int rightNum(int size) {
	int level = 1;
	int totalN = 1;
	int levelN = 1;
	while ((totalN + levelN * 2) <= size) {
		totalN  = totalN + levelN * 2;
		levelN = levelN * 2;
		++level;
	}
	return fullNum(level-2);
}

void fillCBST(int *S, int size, int *CBST) {
	return;
}

int main () {
	freopen("test.txt", "r", stdin);
	int N;
	cin >> N;
	int *tmp = new int[N];
	for (int i=0; i<N; ++i) {
		cin >> tmp[i];
	}
	sort(tmp, tmp+N);
	int *CBST = new int[N];
	fillCBST(tmp, N, CBST);
	outPut(tmp, N, false);
	return 0;
}