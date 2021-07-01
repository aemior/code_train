#include <bits/stdc++.h>

using namespace std;

int N = 8;
int *queens;
int res[92][8];
int num = 0;

void nQueen(int n){
	if (n == N) {
		/*
		for (int i=0; i<N; ++i) {
			cout << queens[i] << ' ';
		}
		cout << endl;
		*/
		for (int i=0; i<8; i++) {
			res[num][i] = queens[i] + 1;
		}
		++num;
		return;
	}
	for (int i=0; i<N; ++i) {
		int j = 0;
		for (; j<n; ++j) {
			if (queens[j] == i||
			    abs(queens[j]-i) == abs(j-n)) {
				break;
			}
		}
		if (j == n) {
			queens[n] = i;
			nQueen(n+1);
		}
	}
	return;
}

int main(){
	queens = new int[N];
	nQueen(0);
	delete [] queens;
	int tmp, b;
	cin >> tmp;
	for (int i=0; i<tmp; ++i) {
		cin >> b;
		for(int j=0; j<8; ++j) {
			cout << res[b-1][j];
		}
		cout << endl;
	}
	return 0;
}