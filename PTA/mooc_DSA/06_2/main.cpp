#include <bits/stdc++.h>

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
};


bool DFShelper(Point *ps, bool *v, int on, int s, int D) {
	if ((ps+on)->touchDown(D)) return true;
	for (int i=0; i<s; ++i) {
		if (!*(v+i) && (ps+on)->to(*(ps+i)) <= D) {
			*(v+i) = true;
			if (DFShelper(ps, v, i, s, D)) return true;
		}
	}
	return false;
}

bool DFS(Point *ps, int s, int D) {
	if (Point(0,0).touchDown(D)) return true;
	bool visted[s];
	memset(visted, false, sizeof(bool)*s);
	for (int i=0; i<s; ++i) {
		if (!visted[i] && (ps+i)->to(D)) {
			visted[i] = true;
			if (DFShelper(ps, visted, i, s, D)) return true;
		}
	}
	return false;
}

bool testExist(string name) {
    ifstream f(name.c_str());
    return f.good();
}

int main (int argc, char *argv[]) {
	if (argc-1) freopen(argv[1], "r", stdin);
	else if (testExist("test.txt")) freopen("test.txt", "r", stdin);
	int N,D;
	cin >> N >> D;
	Point *points = new Point[N];
	if (DFS(points, N, D)) cout << "Yes";
	else cout << "No";
	delete []points;
	return 0;
}