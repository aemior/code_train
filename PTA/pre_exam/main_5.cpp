#include <bits/stdc++.h>

using namespace std;

int main () {
	vector<string> decode;
	char list[4] = {'S', 'H', 'C', 'D'};
	for (int i=0; i<4; ++i) {
		for (int j=1; j<14; ++j) {
			decode.push_back(list[i]+to_string(j));
		}
	}
	decode.push_back("J1");
	decode.push_back("J2");

	int K;
	int buf[54];
	int buf1[54];
	int buf2[54];
	bool tiktok = true;
	cin >> K;
	for (int i=0; i<54; ++i) {
		cin >> buf[i];
		buf[i]--;
		buf1[i] = i;
	}
	while (K--)
	{
		if (tiktok){
			for (int i=0; i<54; ++i) {
				buf2[i] = buf[buf1[i]];
			}
			tiktok = false;
		} else {
			for (int i=0; i<54; ++i) {
				buf1[i] = buf[buf2[i]];
			}
			tiktok = true;
		}
	}
	bool space = false;
	for (int i=0; i<54; ++i) {
		if (space) cout << ' ';
		for (int j=0; j<54; ++j){
			if (tiktok) {
				if (buf1[j] == i) {
					cout << decode[j];
					space = true;
				}
			} else {
				if (buf2[j] == i) {
					cout << decode[j];
				}
			}
		}
		space = true;
	}
	cout << endl;
	return 0;
}