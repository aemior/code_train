#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX_LEN 1001

char s1[MAX_LEN];
char s2[MAX_LEN];

int l1,l2,lmin;

int MAX[MAX_LEN][MAX_LEN];

int main () {
	freopen("test.txt", "r", stdin);
	while(scanf("%s %s\n", s1, s2) != EOF) {
		l1 = strlen(s1);
		l2 = strlen(s2);
		lmin = l1<l2?l1:l2;
		if (!lmin) {
			cout << 0 << endl;
			continue;
		}
		for (int i=0; i<=l1; ++i) {
			for (int j=0; j<=l2; ++j) {
				if (i == 0 || j == 0) {
					MAX[i][j] = 0;
				}else if (s1[i-1] == s2[j-1]) {
					MAX[i][j] = MAX[i-1][j-1] + 1;
				} else {
					MAX[i][j] = max(MAX[i-1][j], MAX[i][j-1]);
				}
			}
		}
		cout << MAX[l1][l2] << endl;
	}
	return 0;
}