#include <bits/stdc++.h>

using namespace std;

void int2bin(int i){
	if (i == 2) {
		cout << '2';
	} else if (i == 0) {
		cout << '0';
	}
	else {
		bool pflg = false;
		for (int j=16; j>=0; --j) {
			if ((i >> j) & 1) {
				if (pflg) {
					cout <<  '+';
				}
				cout <<  '2';
				if (j != 1) {
					cout << "(";
					int2bin(j);
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
	cout << endl;
	return 0;
}