#include <bits/stdc++.h>

using namespace std;

typedef struct NODE {
	NODE(int d, NODE *n) {
		Data = d;
		Next = n;
	}
	int Data;
	NODE *Next;
} node;

class SocialNet{
	private:
		node **V;
		int Size;
		int E;
		bool *v;
		void BFShelper(int c) {
			node *tmp;
			int cnt = 1, ls = 1, s = 0, level=6;
			queue<int> q;
			memset(v, false, sizeof(bool)*Size);
			q.push(c);
			v[c] = true;
			while (q.size() && level) {
				if (ls--) {
					tmp = *(V+q.front());
					q.pop();
					while (tmp) {
						if (!v[tmp->Data]) {
							++s;
							q.push(tmp->Data);
							v[tmp->Data] = true;
							++cnt;
						}
						tmp = tmp->Next;
					}
				} else {
					ls = s;
					s = 0;
					--level;
				}
			}
			printf("%d: %.2f%%\n", c+1, ((float)cnt/(float)Size)*100.00);
		}
	public:
		SocialNet(int s):Size(s) {
			V = new node*[s];
			memset(V, 0, sizeof(node*)*s);
		}
		SocialNet(){
			cin >> Size >> E;
			V = new node*[Size];
			memset(V, 0, sizeof(node*)*Size);
			node *tmp;
			int a,b;
			for (int i=0; i<E; ++i) {
				scanf("%d %d\n", &a, &b);
				--a,--b;
				*(V+a) = new node(b, *(V+a));
				*(V+b) = new node(a, *(V+b));
			}
			v = new bool[Size];
		}
		/*
		~SocialNet(){
			node *tmp;
			for (int i=0; i<Size; ++i) {
				while (*(V+i)) {
					tmp = *(V+i);
					*(V+i) = (*(V+i))->Next;
					delete tmp;
				}
			}
			if (Size) {
				delete []V;
				delete []v;
			}
		}
		*/
		void BFS() {
			for (int i=0; i<Size; ++i)
				BFShelper(i);
		}
		void printGraph() {
			node *tmp;
			for (int i=0; i<Size; ++i) {
				printf("%d||", i+1);
				tmp = V[i];
				while (tmp)
				{
					printf("-->%d", tmp->Data+1);
					tmp = tmp->Next;
				}
				printf("-->X\n");
			}
		}
};

bool testExist(string name) {
    ifstream f(name.c_str());
    return f.good();
}

int main (int argc, char *argv[]) {
	if (argc-1) freopen(argv[1], "r", stdin);
	else if (testExist("test.txt")) freopen("test.txt", "r", stdin);
	SocialNet s;
	//s.printGraph();
	s.BFS();
	return 0;
}