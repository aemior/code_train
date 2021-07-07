#include <bits/stdc++.h>

using namespace std;

int main () {
	//freopen("test.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	M = M%N;
	int *data = new int[N]; 
	for (int i=0; i<N; ++i) {
		cin >> data[i];
	}
	bool flg = false;
	for (int i=0; i<M; ++i) {
		if (flg) cout << ' ';
		cout << data[N-M+i];
		flg = true;
	}
	for (int i=0; i<N-M; ++i) {
		if (flg) cout << ' ';
		cout << data[i];
		flg = true;
	}
	cout << endl;
	return 0;
}