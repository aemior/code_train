#include <bits/stdc++.h>

using namespace std;


template<class T1>
void modeVector(vector<T1> &v, bool(*p)(T1)){
	bool FLG = true;
	while (FLG) {
		FLG = false;
		for (auto it = v.begin(); it != v.end(); ++it) {
			if (p(*it)) {
				v.erase(it);
				FLG = true;
				break;
			}
		}
	}
}

bool equ2(int i) {
	return i==2;
}

int main () {
	//vector<int> test = {2, 2, 2, 3, 2, 2, 2, 4, 2};
	vector<int> test;
	modeVector<int>(test, equ2);
	for (auto it=test.begin(); it != test.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}