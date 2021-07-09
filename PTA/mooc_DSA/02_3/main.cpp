#include <bits/stdc++.h>

using namespace std;


struct NODE {
	int V, ADD, NEX;
	NODE(){}
	NODE(int ad, int v, int nex):V(v), ADD(ad), NEX(nex){}
	NODE *next;
};

int N, K, HEAD, h, next;
int Address, Data, Next;

map<int, NODE> buff;

void reverK(NODE *&head, int k) {
	NODE *l = NULL, *n ,*p = head;
	for (int i=0; head && i<k; ++i) {
		n = head->next;
		head->next = l;
		l = head;
		head = n;
	}
	if (l) {
		p->next = head;
		head = l;
	} else return;
	p = head;
	while (--k)
	{
		p->NEX = p->next->ADD;
		p = p->next;
	}
	if (p->next)
		p->NEX = p->next->ADD;
	else
		p->NEX = -1;
}

void printL(NODE *h) {
	while (h->next)
	{
		cout <<setfill('0')<<setw(5) << h->ADD << ' ' << h->V << ' ' << setfill('0')<<setw(5) << h->NEX << endl;
		h = h->next;
	}
	cout <<setfill('0')<<setw(5)<< h->ADD << ' ' << h->V << ' ' << h->NEX << endl;
}

int main () {
	//freopen("test.txt", "r", stdin);
	cin >> HEAD >> N >> K;
	if (!N) cout << "00000 0 -1" << endl; 
	while (cin >> Address >> Data >> Next) {
		//cin >> Address >> Data >> Next;
		buff[Address] = NODE(Address, Data, Next);
	}
	int cnt=1;
	NODE *head = &(buff[HEAD]);
	NODE *p = head;
	while (p->NEX != -1) {
		p->next = &(buff[p->NEX]);
		p = p->next;
		cnt++;
	}
	p->next = NULL;
	if (cnt/K)
		reverK(head, K);
	else {
		int Z = K;
		if (K/(2*cnt)) {
			Z = K%(2*cnt);
		}
		if (Z > cnt) {
			reverK(head, cnt);
			reverK(head, Z%cnt);
		} else {
			reverK(head, Z);
		}
	}
	printL(head);
	return 0;
}