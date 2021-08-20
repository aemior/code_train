#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_L 101

struct POINT{
	int R;
	int C;
	int A;
};

bool operator<(const POINT &p1, const POINT p2) {
	return p1.A < p2.A;
}

POINT *DATA;
int MAP[MAX_L][MAX_L];
int DIS[MAX_L][MAX_L];

int R,C,N;

int main () {
	freopen("test.txt", "r", stdin);
	cin >> R >> C;
	N = R*C;
	DATA = new POINT[N];
	int n=0;
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			DATA[n].C = j;
			DATA[n].R = i;
			cin >> MAP[i][j];
			DATA[n++].A = MAP[i][j];
		}
	}
	sort(DATA, DATA+N);
	int max_n=0;
	for (n=0; n<N; ++n) {
		DIS[DATA[n].R][DATA[n].C] = 1;
		if (DATA[n].R - 1 >= 0) {
			if (MAP[DATA[n].R - 1][DATA[n].C] < MAP[DATA[n].R][DATA[n].C] && 
			    DIS[DATA[n].R - 1][DATA[n].C] + 1 > DIS[DATA[n].R][DATA[n].C]) {
					DIS[DATA[n].R][DATA[n].C] = DIS[DATA[n].R - 1][DATA[n].C] + 1;
				}
		}
		if (DATA[n].C - 1 >= 0) {
			if (MAP[DATA[n].R][DATA[n].C - 1] < MAP[DATA[n].R][DATA[n].C] && 
			    DIS[DATA[n].R][DATA[n].C - 1] + 1 > DIS[DATA[n].R][DATA[n].C]) {
					DIS[DATA[n].R][DATA[n].C] = DIS[DATA[n].R][DATA[n].C - 1] + 1;
				}
		}
		if (DATA[n].R + 1 < R) {
			if (MAP[DATA[n].R + 1][DATA[n].C] < MAP[DATA[n].R][DATA[n].C] && 
			    DIS[DATA[n].R + 1][DATA[n].C] + 1 > DIS[DATA[n].R][DATA[n].C]) {
					DIS[DATA[n].R][DATA[n].C] = DIS[DATA[n].R + 1][DATA[n].C] + 1;
				}
		}
		if (DATA[n].C + 1 < C) {
			if (MAP[DATA[n].R][DATA[n].C + 1] < MAP[DATA[n].R][DATA[n].C] && 
			    DIS[DATA[n].R][DATA[n].C + 1] + 1 > DIS[DATA[n].R][DATA[n].C]) {
					DIS[DATA[n].R][DATA[n].C] = DIS[DATA[n].R][DATA[n].C + 1] + 1;
				}
		}
		if (DIS[DATA[n].R][DATA[n].C] > max_n) max_n = DIS[DATA[n].R][DATA[n].C];
	}
	cout << max_n;
	return 0;
}
