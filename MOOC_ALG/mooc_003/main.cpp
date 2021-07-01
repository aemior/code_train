#include <bits/stdc++.h>

using namespace std;

char s[10];

void permutation(const char *head, const char *sget) {
	int len = strlen(sget);
	if (len == 1) {
		cout << head << sget << endl;
	} else {
		for (int i=0; i<len; ++i) {
			char tmp[10], ns[10];
			strcpy(tmp, head);
			tmp[strlen(head)] = sget[i];
			tmp[strlen(head)+1] = 0;
			int j=0;
			for (int k=0; k<len; ++k) {
				if (k != i) {
					ns[j] = sget[k];
					++j;
				}
			}
			ns[j] = 0;
			permutation(tmp, ns);
		}
	}
}

int main(){
	cin >> s;
	permutation("\0", s);
	return 0;
}