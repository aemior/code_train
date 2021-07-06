#include <bits/stdc++.h>

using namespace std;

map<int, set<int> > data;
typedef map<int, set<int> >::iterator III;
int N, a, b;

int main () {
	freopen("test.txt", "r", stdin);
	data[1000000000] = set<int>({1});
	cin >> N;
	while (N--)
	{
		cin >> a >> b;
		cout << a <<  ' ';
		if (data.find(b) == data.end()) {
			pair<III, III> res = data.equal_range(b);
			if (res.first == data.begin()) {
				cout << *(res.second->second.begin()) << endl;
			} else {
				--res.first;
				if (abs(res.first->first - b) > abs(res.second->first - b)) {
					cout << *(res.second->second.begin()) << endl;
				} else if (abs(res.first->first - b) < abs(res.second->first - b)){
					cout << *(res.first->second.begin()) << endl;
				} else if (*(res.first->second.begin()) < *(res.second->second.begin())) {
					cout << *(res.first->second.begin()) << endl;
				} else {
					cout << *(res.second->second.begin()) << endl;
				}
			}
			data[b] = set<int>({a});
		} else {
			cout << *(data.find(b)->second.begin()) << endl;
			data.find(b)->second.insert(a);
		}
	}
	
	return 0;
}