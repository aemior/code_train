#include <bits/stdc++.h>

using namespace std;

int place_apple(int M, int N);

int main () {
	int t,M,N;
	cin >> t;
	while (t--) {
		cin >> M >> N;
		cout << place_apple(M, N) << endl;
	}
	return 0;
}

int place_apple(int M, int N) {
	if (M < N) {
		return place_apple(M, M);
	} else if (M == 0) {
		return 1;
	} else if (N == 0) {
		return 0;
	}
	return place_apple(M, N-1) + place_apple(M-N, N);
}
