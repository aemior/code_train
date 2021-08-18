//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX_NUM 100

int N;

int DATA[MAX_NUM+10][MAX_NUM+10];
int MS[MAX_NUM+10][MAX_NUM+10];

int MaxSum(int i, int j) {
	if (i >= N-1) return DATA[i][j];
	int A = MaxSum(i+1, j);
	int B = MaxSum(i+1, j+1);
	return A>B?DATA[i][j]+A:DATA[i][j]+B;
}

int main () {
	//freopen("test.txt", "r", stdin);
	cin >> N;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<i+1; ++j) {
			cin >> DATA[i][j];
		}
	}
	for (int j=0; j<N-1; ++j)
		MS[N-1][j] = DATA[N-1][j];
	for (int i=N-2; i>=0; --i) {
		for (int j=0; j < i+1; ++j) {
			MS[i][j] = DATA[i][j] + (MS[i+1][j]>MS[i+1][j+1]?MS[i+1][j]:MS[i+1][j+1]);
		}
	}
	//cout << MaxSum(0,0) << endl;
	cout << MS[0][0];
	return 0;
}