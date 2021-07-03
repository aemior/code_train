#include <iostream>
using namespace std;
int main () {
	int N;
	cin >> N;
	cin.get();
	while (N--)
	{
		char buf[90];
		cin.getline(buf, 85);
		int res = 0, cnt = 0;
		for (int i=0; buf[i]; ++i) {
			if (buf[i] == 'O') {
				res += ++cnt;
			} else if (buf[i] == 'X') {
				cnt = 0;
			}
		}
		cout << res << endl;
	}
	return 0;
}