#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

map<char, double> tab = {{'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01}};
char buf[90];

double getTerm(int idx, double base) {
	int fac = 0;
	for (;buf[idx] > '0' && buf[idx] < '9'; ++idx) {
		fac = fac * 10 + (buf[idx] - '0');
	}
	if (fac) {
		return base * fac;
	}
	return base;
}

int main () {
	//freopen("test.txt", "r", stdin);
	double res;
	int N;
	cin >> N;
	cin.get();
	while (N--) {
		res = 0;
		cin.getline(buf, 90);
		for (int i=0; buf[i]; ++i) {
			if (tab.find(buf[i]) != tab.end()) {
				res += getTerm(i+1, tab[buf[i]]);
			}
		}
		cout << fixed << setprecision(3) << res << endl;
	}
	return 0;
}