#include <bits/stdc++.h>

using namespace std;

multiset<int> data;
set<int> flg;

int main() {
	freopen("test.txt", "r", stdin);
	string cmd;
	int N, i;
	cin >> N;
	while (N--)
	{
		cin >> cmd;
		if (cmd == "add") {
			cin >> i;
			data.insert(i);
			flg.insert(i);
			cout << data.count(i) << endl;

		} else if (cmd == "ask") {
			cin >> i;
			if (flg.find(i) != flg.end()) {
				cout << "1 ";
			} else {
				cout << "0 ";
			}
			cout << data.count(i) << endl;
		} else if (cmd == "del") {
			cin >> i;
			cout << data.count(i) << endl;
			multiset<int>::iterator a = data.find(i);
			while (a != data.end() && *a == i) {
				a = data.erase(a);
			}
		};
	}
	return 0;
}