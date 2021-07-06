#include <bits/stdc++.h>

using namespace std;
map<int, int> data;
int main (){
	data[1000000000] = 1; 
	freopen("test.txt", "r", stdin);
	typedef map<int ,int>::iterator III;
	int N, a, b;
	cin >> N;
	while (N--) {
		cin >> a >> b;
		cout << a << ' ';
		pair<III, III> res = data.equal_range(b);
		if (res.first == data.begin()) {
			cout << res.second->second << endl;
		} else {
			--res.first;
			if (abs(res.first->first - b) > abs(res.second->first - b)) {
				cout << res.second->second << endl;
			} else {
				cout << res.first->second << endl;
			}
		}
		data[b] = a;
	}
	return 0;
}
