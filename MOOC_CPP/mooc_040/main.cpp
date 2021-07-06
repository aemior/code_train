#include <bits/stdc++.h>

using namespace std;

map<int, list<int> > data;

void mynew(int i){
	data[i] = list<int>();
}

void myadd(int i, int num){
	for (list<int>::iterator it=data[i].begin(); it != data[i].end(); ++it) {
		if (num < *it) {
			data[i].insert(it, num);
			return;
		}
	}
	data[i].insert(data[i].end(), num);
}

void mymerge(int i1, int i2) {
	data[i1].merge(data[i2]);
}

void myunique(int i){
	data[i].unique();
}

void myout(int i){
	bool flg = false;
	for (list<int>::iterator it=data[i].begin(); it != data[i].end(); ++it) {
		if (flg) cout << ' ';
		cout << *it;
		flg = true;
	}
	cout << endl;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, i1, i2;
	string cmd;
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "new") {
			cin >> i1;
			mynew(i1);
		} else if (cmd == "add") {
			cin >> i1 >> i2;
			myadd(i1, i2);
		} else if (cmd == "merge") {
			cin >> i1 >> i2;
			mymerge(i1, i2);

		} else if (cmd == "unique"){
			cin >> i1;
			myunique(i1);
		} else if (cmd == "out") {
			cin >> i1;
			myout(i1);
		}
	}
	return 0;
}