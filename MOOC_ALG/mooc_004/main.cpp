#include <bits/stdc++.h>

using namespace std;

void int2bin(int i){
	if (i==2) {
		cout << '2';
	} else if (i == 1) {
		cout << "2(0)";
	}
	else {
		bool pflg = false;
		for (int j=16; j>0; --j) {
			if ((i >> j) & 1) {
				if (pflg) {
					cout <<  '+';
				}
				if (j>2) {
					cout << "2(";
				}
				int2bin(j);
				if (j>2) {
					cout << ')';
				}
				pflg = true;
			}
		}
	}
}

int main(){
	int I;
	cin >> I;
	int2bin(I);
	return 0;
}