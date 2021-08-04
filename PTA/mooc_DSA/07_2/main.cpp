#include <bits/stdc++.h>

#define MAX_L 20000

using namespace std;

class Point {
	private:
		int X,Y;
	public:
		Point() {
			cin >> X >> Y;
		}
		Point(int x, int y):X(x), Y(y) {}
		double to(const Point &p2) const {
			return sqrt((X-p2.X)*(X-p2.X) + (Y-p2.Y)*(Y-p2.Y));
		}
		bool touchDown(int D) {
			return ((50 - abs(X)) <= D) || ((50 - abs(Y)) <= D);
		}
		bool to(int D) {
			double x = X, y = Y, d = D;
			return (sqrt(x*x + y*y) - 7.5) <= d;
		}
		double MFJ() {
			double x = X, y = Y;
			return sqrt(x*x + y*y) - 7.5;
		}
		void Print(bool nl = true) {
			cout << X << ' ' << Y;
			if (nl) cout << endl;
		}
};

class Solve {
	private:
		int V;
		int D;
		int *path;
		int *resPath;
		int *dist;
		Point *P;
		void ShortestPath();
		void BFS(int);
		int minSteps;
		int pathShore;
		double MFJ = MAX_L;
	public:
		Solve () {
			cin >> V >> D;
			P = new Point[V];
			path = new int[V];
			resPath = new int[V];
			dist = new int[V];
			memset(path, -1, sizeof(int)*V);
			memset(dist, MAX_L, sizeof(int)*V);
		}
		void solve();
};

void Solve::BFS(int c) {
	memset(path, -1, sizeof(int)*V);
	memset(dist, MAX_L, sizeof(int)*V);
	dist[c] = 1;
	int tmp, Dshore=MAX_L, Pshore=-1;
	queue<int> q;
	q.push(c);
	while (q.size()) {
		tmp = q.front();
		q.pop();
		if (P[tmp].touchDown(D) && dist[tmp]+1 < Dshore) {
			Dshore = dist[tmp] + 1;
			Pshore = tmp;
		} else {
			for (int i=0; i<V; ++i) {
				if (P[tmp].to(P[i]) <= D && dist[tmp]+1 < dist[i]) {
					dist[i] = dist[tmp] + 1;
					path[i] = tmp;
					q.push(i);
				}
			}
		}
	}
	if ((minSteps && Dshore < minSteps) || (!minSteps && Dshore < MAX_L) || (Dshore == minSteps && P[c].MFJ() < MFJ)) {
		MFJ = P[c].MFJ();
		minSteps = Dshore;
		pathShore = Pshore;
		memcpy(resPath, path, sizeof(int)*V);
	}
}

void Solve::ShortestPath() {
	if (D-7.5 >= 50) {
		minSteps = 1;
		return;
	}
	for (int i=0; i<V; ++i) {
		if (P[i].to(D)) {
			BFS(i);
		}
	}
}

void Solve::solve() {
	minSteps = 0;
	ShortestPath();
	cout << minSteps;
	if (minSteps != 1) cout << endl;
	if (minSteps > 1) {
		stack<int> s;
		s.push(pathShore);
		while (resPath[pathShore] != -1) {
			pathShore = resPath[pathShore];
			s.push(pathShore);
		}
		while (s.size()) {
			P[s.top()].Print(s.size() != 1);
			s.pop();
		}
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