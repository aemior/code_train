#include <bits/stdc++.h>

using namespace std;

template<class T1, class T2>
class graph{
	private:
		int Nv;
		int Ne;
		T1 *V;
		T2 *G;
		T1 defaultV;
		T1 defaultE;
		int cnt;
		void DFShelper(int idx, bool *visted, bool p) {
			for (int i=0; i<Nv; ++i) {
				if (G[Nv*idx+i]) {
					if (!*(visted+i)) {
						if (p)
							cout << i << ' ';
						*(visted+i) = true;
						DFShelper(i, visted, p);
					}
				}
			}
		}
		void BFShelper(queue<int> &q, bool *visted, bool p) {
			int idx;
			while (q.size()) {
				idx = q.front();
				q.pop();
				if (p) {
					cout << idx << ' ';
				}
				for (int i=0; i<Nv; ++i) {
					if (G[Nv*idx+i] && !*(visted+i)) {
						*(visted+i) = true;
						q.push(i);
					}
				}
			}
		}
	public:
		graph(int nv, int ne):Nv(nv), Ne(ne) {
			V = new T1[nv];	
			G = new T2[nv*nv];
		}
		void setInit(T1 v, T2 e) {
			defaultV = v;
			defaultE = e;
			memset(V, v, sizeof(T1)*Nv);
			memset(G, e, sizeof(T2)*Nv*Nv);
		}
		void readEdges(T2 de) {
			int i,j;
			for (int k=0; k<Ne; ++k) {
				scanf("%d %d\n", &i, &j);
				G[Nv*i+j] = de;
				G[Nv*j+i] = de;
			}
		}
		void DFS(bool p=true) {
			cnt = 0;
			bool visted[Nv];
			memset(visted, false, sizeof(bool)*Nv);
			for (int i=0; i<Nv; ++i) {
				if (!visted[i]) {
					++cnt;
					if (p)
						cout << "{ " << i << ' ';
					visted[i] = true;
					DFShelper(i, visted, p);
					if (p)
						cout << '}' << endl;
				}
			}
		}
		void BFS(bool p=true) {
			queue<int> q;
			bool visted[Nv];
			memset(visted, false, sizeof(bool)*Nv);
			for (int i=0; i<Nv; ++i) {
				if (!visted[i]) {
					--cnt;
					if (p)
						cout << "{ ";
					visted[i] = true;
					q.push(i);
					BFShelper(q, visted, p);
					if (p)
						cout << '}';
					if (cnt)
						cout << endl;
				}
			}
		}
};

int main () {
	freopen("test.txt", "r", stdin);
	int N, E;
	cin >> N >> E;
	graph<int, int> g(N, E);
	g.setInit(0, 0);
	g.readEdges(1);
	g.DFS();
	g.BFS();
	return 0;
}