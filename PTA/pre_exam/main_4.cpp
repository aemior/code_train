#include <bits/stdc++.h>

using namespace std;

int main () {
	//freopen("test_4.txt", "r", stdin);
	char N[50], D[50];
	int buf1[10], buf2[10];
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));
	bool FLG = false;
	int I=0, J=0, tmp;
	char t = cin.peek();
	while (t <= '9' && t >= '0')
	{
		tmp = cin.get() - '0';
		t = cin.peek();
		N[I++] = tmp;
		buf1[tmp]++;
	}
	int ac = 0, tc;
	for (int i=I-1; i>=0; --i) {
		tc = ac + N[i]*2;
		D[J++] = tc % 10;
		buf2[tc%10]++;
		ac = tc/10;
	}
	if (ac) {
		D[J++] = ac;
		buf2[ac]++;
	}
	
	int i=0;
	for (; i<10; ++i) {
		if (buf1[i] != buf2[i]) {
			cout << "No" << endl;
			break;
		}
	}
	if (i == 10)
		cout << "Yes" << endl;
	for (i=J-1; i>=0; --i) {
		cout << char(D[i]+'0');
	}
	return 0;
}