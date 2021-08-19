#include <iostream>

using namespace std;

#define MAX_NUM 100

int N;

int DATA[MAX_NUM+10][MAX_NUM+10];
int MS[2][MAX_NUM+10];

int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<i+1; ++j) {
			cin >> DATA[i][j];
		}
	}
	for (int j=0; j<N-1; ++j)
		MS[(N-1)%2][j] = DATA[N-1][j];
	for (int i=N-2; i>=0; --i) {
		for (int j=0; j < i+1; ++j) {
			MS[i%2][j] = DATA[i][j] + (MS[(i+1)%2][j]>MS[(i+1)%2][j+1]?MS[(i+1)%2][j]:MS[(i+1)%2][j+1]);
		}
	}
	cout << MS[0][0];
	return 0;
}