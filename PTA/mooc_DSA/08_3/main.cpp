#include <bits/stdc++.h>

using namespace std;

typedef struct GRAPHNODE{
	int S;
	int D;
	int T;
	GRAPHNODE *Next;
	GRAPHNODE ():Next(NULL) {}
	GRAPHNODE (int s, int d, int t, GRAPHNODE *n):S(s), D(d), T(t), Next(n) {}
} Gnode;

void setIntArray(int *a, int s, int v) {
	for (int i=0; i<s; ++i) {
		a[i] = v;
	}
}

class Solve {
	private:
		Gnode **Graph;
		int Nv;
		int Ne;
		int *ID;
		int *OD;
		int *CP;
		bool TopSort(int*);
		bool CritialPath(int d) {
			if (!OD[d]) return true;
			else {
				Gnode *W;
				for (W = Graph[d]; W; W = W->Next) {
					if (CritialPath(W->D)) CP[d] = 1;

				}
			}
		}
	public:
		Solve () {
			cin >> Nv >> Ne;
			Graph = new Gnode*[Nv];
			memset(Graph, 0, sizeof(Gnode*)*Nv);
			int s, d, t;
			for (int i=0; i<Ne; ++i) {
				cin >> s >> d >> t;
				--s,--d;
				Graph[s] = new Gnode(s,d,t,Graph[s]);
			}
		}
		void solve();
};

bool Solve::TopSort(int *TopOrder) {
	int *Indegree = new int[Nv];
	ID = new int[Nv];
	OD = new int[Nv];
	memset(Indegree, 0, sizeof(int)*Nv);
	Gnode *W;
	for (int i=0; i<Nv; ++i) {
		for (W = Graph[i]; W; W = W->Next) {
			++Indegree[W->D];
			++OD[W->S];
		}
	}
	memcpy(ID, Indegree, sizeof(int)*Nv);
	queue<int> q;
	for (int i=0; i<Nv; ++i) {
		if (!Indegree[i]) q.push(i);
	}
	int cnt=0, V;
	while (q.size()) {
		V = q.front();
		TopOrder[cnt++] = V;
		q.pop();
		for (W = Graph[V]; W; W = W->Next) {
			if (--Indegree[W->D] == 0) q.push(W->D);
		}
	}
	if (cnt != Nv) return false;
	return true;
}

void Solve::solve() {
	int *Earlist = new int[Nv];
	int *Latest = new int[Nv];
	int *TopOrder = new int[Nv];
	memset(Earlist, 0, sizeof(int)*Nv);
	setIntArray(Latest, Nv, INT_MAX);
	Gnode *W;
	if (TopSort(TopOrder)) {
		int gobalLatest;
		for (int i=0; i<Nv; ++i) {
			for (W = Graph[TopOrder[i]]; W; W = W->Next) {
				if (Earlist[TopOrder[i]] + W->T > Earlist[W->D])
					Earlist[W->D] = Earlist[TopOrder[i]] + W->T; 
			}
		}
		gobalLatest = *(max_element(Earlist, Earlist+Nv));
		cout << gobalLatest << endl;
		for (int i=0; i<Nv; ++i) {
			if (!OD[i]) Latest[i] = gobalLatest;
		}
		for (int i=Nv-1; i>=0; --i) {
			for (W = Graph[TopOrder[i]]; W; W = W->Next) {
				if (Latest[W->D] - W->T < Latest[TopOrder[i]]) {
					Latest[TopOrder[i]] = Latest[W->D] - W->T;
				}
			}
		}
		for (int i=0; i<Nv; ++i) {
			for (W = Graph[i]; W; W = W->Next) {
				if (Latest[W->D] - W->T == Earlist[i])
					cout << i+1 << "->" << W->D+1 << endl;
			}
		}
	} else {
		cout << 0;
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