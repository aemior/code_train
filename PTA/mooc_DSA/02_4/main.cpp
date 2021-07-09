#include <bits/stdc++.h>

using namespace std;


int M, N, K, tmp, q;

int *buff;

bool yes;

int main () {
	//freopen("test.txt", "r", stdin);
	cin >> M >> N >> K;
	buff = new int[N];
	while (K--) {
		stack<int> s;
		q = 1;
		for (int i=0; i<N; ++i) {
			cin >> buff[i];
		}
		for (int i=0; i<N; ++i) {
			yes = false;
			tmp = buff[i];
			if (q == tmp && s.size() < M) {
				yes = true;
				q++;
				continue;
			} else if (!s.empty() && s.top() == tmp) {
				yes = true;
				s.pop();
			} else {
				while (q <= N) {
					if (s.size() < M-1)
						s.push(q);
					else {
						yes = false;
						break;
					}
					q++;
					if (q == tmp) {
						yes = true;
						q++;
						break;
					}
				}
				if (!yes) break;
			}
		}
		if (yes) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	delete []buff;
	return 0;
}