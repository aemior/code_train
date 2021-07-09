#include <bits/stdc++.h>

using namespace std;

struct NODE
{
	int a;
	int b;
	NODE(){}
	NODE(int A, int B):a(A), b(B){};
	NODE *next;
};

NODE * readExp(){
	int length;
	cin >> length;
	NODE *p = new NODE;
	NODE *head = p;
	while (length--)
	{
		p->next = new NODE;
		p = p->next;
		cin >> p->a >> p->b;
	}
	p->next = NULL;
	p = head->next;
	delete head;
	return p;
}

void printExp(NODE *head) {
	bool flg=false;
	while (head) {
		if (flg) cout << " + ";
		cout << head->a << "*x^" << head->b; 
		flg = true;
		head = head->next;
	}
	cout << endl;
}

void printExpR(NODE *h) {
	NODE *hb = h;
	bool flg = false;
	while (h && h->a) {
		if (flg) cout << ' ';
		cout << h->a << ' ' << h->b;
		h = h->next;
		flg = true;
	}
	if (h == hb) cout << "0 0";
	cout << endl;
}

void copyExp(NODE *&dst, NODE *src) {
	while (src) {
		dst->next = new NODE;
		dst = dst->next;
		dst->a = src->a;
		dst->b = src->b;
		src = src->next;
	}
}

NODE * sumExp(NODE *A, NODE *B) {
	NODE *p = new NODE;
	NODE *res = p;
	int tmp;
	while (A && B) {
		if (A->b == B->b) {
			tmp = A->a + B->a;
			if (tmp) {
				p->next = new NODE(tmp, A->b);
				p = p->next;
			}
			A = A->next;
			B = B->next;
		} else if (A->b > B->b) {
			p->next = new NODE(A->a, A->b);
			p = p->next;
			A = A->next;
		} else {
			p->next = new NODE(B->a, B->b);
			p = p->next;
			B = B->next;
		}
	}
	if (A) {
		copyExp(p, A);
	}
	if (B) {
		copyExp(p, B);
	}
	p->next = NULL;
	p = res->next;
	delete res;
	return p;
}

void mergeET(NODE *&E, NODE *T) {
	NODE *head = new NODE, *last;
	head->next = E;
	last = head;
	while (E)
	{
		if (E->b == T->b) {
			E->a = E->a + T->a;
			delete T;
			if (!E->a) {
				last->next = E->next;
				delete E;
			}
			E = head->next;
			delete head;
			return;
		} else if (E->b < T->b) {
			T->next = E;
			last->next = T;
			E = head->next;
			delete head;
			return;
		}
		last = E;
		E = E->next;
	}
	last->next = T;
	E = head->next;
	delete head;
}

NODE * multiExp(NODE *A, NODE *B) {
	NODE *p = new NODE(1000000,1000000);
	NODE *Ahead = A;
	int a,b;
	while (B)
	{
		A = Ahead;
		while (A)
		{
			a = A->a * B->a;
			b = A->b + B->b;
			mergeET(p, new NODE(a,b));
			A = A->next;
		}
		B = B->next;
	}
	return p->next;
}


int main () {
	NODE *A = readExp();
	NODE *B = readExp();
	NODE *C = sumExp(A, B);
	NODE *D = multiExp(A, B);
	printExpR(D);
	printExpR(C);
	return 0;
}