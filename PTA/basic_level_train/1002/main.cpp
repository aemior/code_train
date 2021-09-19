#include <bits/stdc++.h>

using namespace std;

vector<string> PY = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};
vector<int> out_seq;

int main () {
	int sum=0;
	string n;
	cin >> n;
	for (int i=0; i<n.size(); ++i) {
		sum += n[i] - '0';
	}
	while (sum)
	{
		out_seq.push_back(sum%10);
		sum = sum / 10;
	}
	bool flg = false;
	for(int i=out_seq.size()-1; i>=0; --i) {
		if (flg) cout << ' ';
		cout << PY[out_seq[i]];
		flg = true;
	}
	
	
	return 0;
}