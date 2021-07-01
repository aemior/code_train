#include <bits/stdc++.h>

using namespace std;

int *A;
int *B;
int *C;
int N;
map<char, int*> t = {{'A', A}, {'B', B}, {'C', C}};

void hanoi(int n, const char &S, const char &M, const char &D){
	if (n > 1) {
		hanoi(n-1, S, D, M);
		hanoi(1, S, M, D);
		hanoi(n-1, M, S, D);
	}
	else {
		for (int i=0; i<N; ++i) {
			if (t[S][i]) {
				cout << "Move disk " << t[S][i] << " from " << S << " to " << D
				<< endl;
				for (int j=0; j<N; ++j) {
					if (t[D][j]) {
						t[D][j-1] = t[S][i];
						t[S][i] = 0;
						return;
					}
				}
				t[D][N-1] = t[S][i];
				t[S][i] = 0;
				return;
			}

		}

	}
}



int main() {
	cin >> N;
	t['A'] = new int[N];
	t['B'] = new int[N];
	t['C'] = new int[N];
	for (int i=0; i<N; ++i) {
		t['A'][i] = i+1;
		t['B'][i] = 0;
		t['C'][i] = 0;
	}
	hanoi(N, 'A', 'B', 'C');
	return 0;
}