#include <bits/stdc++.h>

using namespace std;

int res[10];

void setRes(){
	for (int i=0; i<10; ++i) {
		res[i] = 0;
	}
}

int main() {
	//freopen("test.txt", "r", stdin);
	int number, N;
	cin >> number;
	while (number--)
	{
		cin >> N;
		setRes();
		for (int i=1; i<=N; ++i) {
			int j=i;
			do {
				res[j%10]++;
			} while (j/=10);
		}
		for (int i=0; i<10; ++i) {
			cout << res[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}