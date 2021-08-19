#include <iostream>
#include <cmath>

using namespace std;

#define MAX_N 3500
#define MAX_W 410

struct JW{
	int W;
	int D;
	bool operator<(const JW &b) const{
		return D > b.D;
	}
};

istream & operator>>(istream &i, JW &j) {
	i >> j.W >> j.D;
	return i;
}

int N, M;
JW DATA[MAX_N];

int F[13000];

int main () {
	//freopen("test.txt", "r", stdin);
	cin >> N >> M;
	for (int i=1; i<=N; ++i) {
		cin >> DATA[i];
	}
	for (int j=0; j<=M; ++j) {
		if (DATA[1].W <= j)
			F[j] = DATA[1].D;
		else
			F[j] = 0;
	}
	for (int i=2; i<=N; ++i) {
		for (int j=M; j>=0; --j) {
			if (DATA[i].W <= j) {
				F[j] = max(F[j], F[j-DATA[i].W] + DATA[i].D);
			}
		}
	}
	cout << F[M] << endl;
	return 0;
}