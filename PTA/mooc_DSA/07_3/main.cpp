#include <bits/stdc++.h>

#define MAX_D 250000

using namespace std;

typedef struct HIGHWAY {
	int D;
	int C;
	HIGHWAY():D(0), C(0){}
	void operator = (HIGHWAY &b) {
		D = b.D;
		C = b.C;
	}
	operator bool() {
		return D;
	}
} hw;

class Point{
	private:
		int X,Y;
	public:
		Point(){}
		Point(int x, int y):X(x),Y(y) {}
};

istream & operator >> (istream &i, hw &a) {
	i >> a.D >> a.C;
	return i;
}

void setIntArray(int *a, int s, int v) {
	for (int i=0; i<s; ++i) {
		a[i] = v;
	}
}

class Solve {
	private:
		int V;
		int E;
		int S;
		int D;
		hw *Data;
		int findMin(int *dist, bool *confirm) {
			int res, cmin=MAX_D;
			for (int i=0; i<V; ++i) {
				if (!confirm[i] && dist[i] < cmin) {
					res = i;
					cmin = dist[i];
				}
			}
			if (cmin == MAX_D) return -1;
			return res;
		}
		void Dijstra(int *dist, int *cost, int *path, bool *confirm) {
			int current;
			while (true) {
				current = findMin(dist, confirm);
				if (current == -1) break;
				else confirm[current] = true;
				for (int i=0; i<V; ++i) {
					if (Data[i*V+current] || Data[current*V+i]) {
						if ((dist[current] + Data[current*V+i].D < dist[i]) ||
						    (dist[current] + Data[current*V+i].D == dist[i] &&
							 cost[current] + Data[current*V+i].C < cost[i])) {
							dist[i] = dist[current] + Data[current*V+i].D;
							cost[i] = cost[current] + Data[current*V+i].C;
							path[i] = current;
						}
					}
				}
			}
		}
	public:
		Solve () {
			cin >> V >> E >> S >> D;
			int x, y, d, c;
			hw tmp;
			Data = new hw[V*V];
			for (int i=0; i<E; ++i) {
				cin >> x >> y >> tmp;
				Data[x*V+y] = tmp;
				Data[y*V+x] = tmp;
			}
		}
		void solve () {
			int *dist = new int[V];
			int *cost = new int[V];
			int *path = new int[V];
			bool *confirm = new bool[V];
			//memset(dist, 25000, sizeof(int)*V);
			//memset(cost, MAX_D, sizeof(int)*V);
			setIntArray(dist, V, MAX_D);
			setIntArray(cost, V, MAX_D);
			memset(path, -1, sizeof(int)*V);
			memset(confirm, 0, sizeof(bool)*V);
			dist[S] = cost[S] = 0;
			Dijstra(dist, cost, path, confirm);
			cout << dist[D] << ' ' << cost[D];
		}
};

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
	DevMode(argc, argv);
	Solve s;
	s.solve();
	return 0;
}