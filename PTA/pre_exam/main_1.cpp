#include <bits/stdc++.h>
using namespace std;
int main () {
    char t;
    int N;
    cin >> N;
	cin.get();
	t = cin.get();
	if (!N) {
		cout << 0 << endl;
		return 0;
	}
    int U = 1;
    int i=3;
    while (true) {
        U = U + 2 * i;
        if (U > N) break;
        i+=2;
    }
    U = U - 2 * i;
    i-=2;
    int space = 0, I=i;
    while (i > 1) {
        for (int j=0; j<space; ++j) {
            cout << ' ';
        }
        for (int j=0; j<i; ++j) {
			cout << t;
			N--;
        }
        cout << endl;
        space += 1;
        i -= 2;
    }
    while (i<=I) {
        for (int j=0; j<space; ++j) {
            cout << ' ';
        }
        for (int j=0; j<i; ++j) {
			cout << t;
			N--;
        }
        cout << endl;
        space -= 1;
        i += 2;
    }
    cout << N << endl;
    return 0;
}