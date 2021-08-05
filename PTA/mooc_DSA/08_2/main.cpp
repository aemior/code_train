#include <bits/stdc++.h>

using namespace std;

class Solve {
	private:
		int N,M;
		int *S;
		int *E;
		int *L;
		int *Graph;
		int *Outdegree;
		bool TopSort(int*);
	public:
		Solve () {
			cin >> N >> M;
			Graph = new int[N*N];
			memset(Graph, 0, sizeof(int)*N*N);
			S = new int[M];
			E = new int[M];
			L = new int[M];
			for (int i=0; i<M; ++i) {
				cin >> S[i] >> E[i] >> L[i];
				Graph[S[i]*N+E[i]] = L[i];
			}
		}
		void solve();

};

bool Solve::TopSort(int *TopOrder) {
	int *Indegree = new int[N];
	Outdegree = new int [N];
	memset(Indegree, 0, sizeof(int)*N);
	memset(Outdegree, 0, sizeof(int)*N);
	for (int i=0; i<N; ++i) {
		int cnt = 0, cntO = 0;
		for (int j=0; j<N; ++j) {
			if (Graph[j*N+i]) cnt++;
			if (Graph[i*N+j]) cntO++;
		}
		Indegree[i] = cnt;
		Outdegree[i] = cntO;
	}
	queue<int> q;
	for (int i=0; i<N; ++i) {
		if (!Indegree[i]) q.push(i);
	}
	int cnt=0, V;
	while (q.size()) {
		V = q.front();
		q.pop();
		TopOrder[cnt++] = V;
		for (int i=0; i<N; ++i) {
			if (Graph[V*N+i]) {
				if (--Indegree[i] == 0) 
				q.push(i);
			}
		}
	}
	if (cnt != N) return false;
	return true;
}

void Solve::solve() {
	int *Earlist = new int[N];
	memset(Earlist, 0, sizeof(int)*N);
	int *TopOrder = new int[N];
	int Latest = INT_MIN;
	if (TopSort(TopOrder)) {
		for (int i=0; i<N; ++i) {
			int tMax = 0;
			for (int j=0; j<N; ++j) {
				if (Graph[j*N+TopOrder[i]] && Earlist[j] + Graph[j*N+TopOrder[i]] > tMax) {
					tMax = Earlist[j] + Graph[j*N+TopOrder[i]];
				}
			}
			Earlist[TopOrder[i]] = tMax;
		}
		for (int i=0; i<N; ++i) {
			if (!Outdegree[i] && Earlist[i] > Latest) Latest = Earlist[i];
		}
		cout << Latest;
	} else {
		cout << "Impossible";
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
	DevMode(argc, argv);
	Solve s;
	s.solve();
	return 0;
}