#include <iostream>

using namespace std;

int N;
int DATA[1001];
int CHAIN[1001];
int MAX[1001];

int main () {
	//freopen("test.txt", "r", stdin);
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> DATA[i];
	}
	for (int i=0; i<N; ++i) {
		MAX[i] = 1;
		CHAIN[i] = 1;
		for (int j=0; j<i; ++j) {
			if (MAX[j] > MAX[i]) MAX[i] = MAX[j];
			if (DATA[j] < DATA[i] && CHAIN[j]+1 > CHAIN[i])
				CHAIN[i] = CHAIN[j] + 1;
		}
		if (CHAIN[i] > MAX[i]) MAX[i] = CHAIN[i];
	}
	cout << MAX[N-1];
}