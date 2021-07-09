#include <bits/stdc++.h>

using namespace std;

struct NODE
{
	int ADD, V, NEX;
	NODE(){}
	NODE(int a, int v, int n):ADD(a), V(v), NEX(n) {}
};

int Head, Address, Data, Next, N, K, idx;
map<int, NODE> buff; 

int main () {
	freopen("test.txt", "r", stdin);
	cin >> Head >> N >> K;
	while (cin >> Address >> Data >> Next) {
		buff[Address] = NODE(Address, Data, Next);
	}
	int cnt=1;
	idx = Head;
	while (buff[idx].NEX != -1)
	{
		idx = buff[idx].NEX;
		cnt++;
	}
	if (cnt < K)
	while (true)
	{
		cout << "Hack" << endl;
	}
	
	bool flg = false;
	int tmp = -1, next = Head, last = -1, l=Head, ll;
	while (true) {
		ll = next;
		for (int i=0; i<K; ++i) {
			last = tmp;
			tmp = next;
			next = buff[next].NEX;
			buff[tmp].NEX = last;
			cnt--;
		}
		if (cnt >= K){
			if (flg) {
				buff[l].NEX = tmp;
				l = ll;
			} else {
				Head = tmp;
				flg = true;
			}
		} else {
			buff[l].NEX = tmp;
			next = ll;
		}
	}
	
	if (tmp == -1) {
		tmp = Head;
	} else {
		buff[Head].NEX = next;
	}
	while (buff[tmp].NEX != -1)
	{
		printf("%05d %d %05d\n", buff[tmp].ADD, buff[tmp].V, buff[tmp].NEX);
		tmp = buff[tmp].NEX;
	}
	printf("%05d %d %d\n", buff[tmp].ADD, buff[tmp].V, buff[tmp].NEX);
	return 0;
}