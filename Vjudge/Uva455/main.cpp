#include <iostream>
#include <cstring>

using namespace std;

char buf[90];

int main () {
	freopen("test.txt", "r", stdin);
	int N;
	char c;
	cin >> N;
	cin.get();
	while (N--)
	{
		cin.get();
		cin.getline(buf, 90);
		int len = strlen(buf);
		int res=0;
		bool flg;
		while (true) {
			++res;
		 	if (len%res != 0) continue;
			flg = true;
			if (res > (len/2)) break;
			for (int fac=1; fac<(len/res); ++fac) {
				for (int i=0; i<res; ++i) {
					if (buf[i] != buf[res*fac+i]) {
						flg = false;
						break;
					}
				}
				if (!flg) break;
			}
			if (flg) break;
		}
		if (!flg) res = len;
		cout << res << endl;
		if (N)
			cout << endl;
	}


	return 0;
}