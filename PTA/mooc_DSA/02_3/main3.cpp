#include <bits/stdc++.h>

using namespace std;

struct NODE
{
	int V,NEX;
	NODE(){}
	NODE(int v, int n):V(v), NEX(n){}
};

NODE nodes[100005];

int N, K, Address, Data, Next, Head;

int n,l,c,h,cnt=0, stail, shead, ltail, lhead;
bool FLG = true;

int main () {
	freopen("test.txt", "r", stdin);
	cin >> Head >> N >> K;
	while (cin >> Address >> Data >> Next) {
		nodes[Address] = NODE(Data, Next);
	}
	n = Head;
	while (n != -1) {
		cnt++;
		n = nodes[n].NEX;
	}

	ltail = lhead = shead = n = Head;
	l = c = -1;

	while (cnt >= K && K > 1) {
		if (cnt >= K) {
			for (int i=0; i<K; ++i) {
				l = c;
				c = n;
				n = nodes[n].NEX;
				nodes[c].NEX = l;
				if (!i) stail = c;
				cnt--;
			}
			shead = c;
		}
		if (FLG) {
			Head = shead;
			FLG = false;
		} else{
			nodes[ltail].NEX = shead;
		}
		ltail = stail;
	}
	if (n != ltail)
		nodes[ltail].NEX = n;
	while (nodes[Head].NEX != -1)
	{
		printf("%05d %d %05d\n", Head, nodes[Head].V, nodes[Head].NEX);
		Head = nodes[Head].NEX;
	}
	printf("%05d %d %d\n", Head, nodes[Head].V, nodes[Head].NEX);
	
	return 0;
}