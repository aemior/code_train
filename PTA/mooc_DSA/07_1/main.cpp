#include <bits/stdc++.h>

#define MAX_L 30000

using namespace std;


class Solve{
	private:
		int *Data;
		int MaxPath = MAX_L;
		int Result;
		int V;
		int E;
		int	FindMin(int *, bool *);
		void FindMaxPath(int s);
		void Dijstra(int *d, int *p, bool *v);
	public:
		Solve() {
			cin >> V >> E;
			Data = new int[V*V];
			memset(Data, 0, sizeof(int)*V*V);
			int x,y;
			for (int i=0; i<E; ++i) {
				cin >> x >> y;
				--x,--y;
				cin >> Data[x*V+y];
				Data[y*V+x] = Data[x*V+y];
			}
		}
		~Solve() {
			if (V) {
				delete []Data;
			}
		}
		void solve() {
			for (int i=0; i<V; ++i) {
				FindMaxPath(i);
			}
			if (MaxPath < MAX_L) {
				cout << Result+1 << ' ' << MaxPath;
			} else {
				cout << 0;
			}
		}

};

int Solve::FindMin(int *d, bool *v) {
	int b = MAX_L;
	int res;
	for (int i=0; i<V; ++i) {
		if (!v[i] && d[i] < b) {
			b = d[i];
			res = i;
		}
	}
	if (b < MAX_L) return res;
	return -1;
}

void Solve::Dijstra(int *d, int *p, bool *v) {
	int currentV;
	while (true) {
		currentV = FindMin(d, v);
		if (currentV < 0) break;
		v[currentV] = true;
		for (int i=0; i<V; ++i) {
			if (!v[i] && Data[currentV*V+i]) {
				if ((d[currentV]+Data[currentV*V+i])<d[i]) {
					d[i] = d[currentV]+Data[currentV*V+i];
					p[i] = currentV;
				}
			}
		}
	}
}

void Solve::FindMaxPath(int s) {
	auto *d = new int[V];
	int *path = new int[V];
	bool *visted = new bool[V];
	memset(d, MAX_L, sizeof(int)*V);
	memset(path, -1, sizeof(int)*V);
	d[s] = 0;
	Dijstra(d, path, visted);
	int localMax = *(max_element(d, d+V));
	if (localMax < MaxPath) {
		MaxPath = localMax;
		Result = s;
	}
}

bool testExist(string name) {
    ifstream f(name.c_str());
    return f.good();
}

void DevMode(int argc, char *argv[]) {
	if (argc-1) {
		freopen(argv[1], "r", stdin);
		cout << "#Debug: open test input file \"" << argv[1] << '\"' << endl;
	}
	else if (testExist("test.txt")) {
		freopen("test.txt", "r", stdin);
		cout << "#Debug: open test input file \"test.txt\"" << endl;
	}
}

int main (int argc, char *argv[]) {
	DevMode(argc,argv);
	Solve s;
	s.solve();
	return 0;
}