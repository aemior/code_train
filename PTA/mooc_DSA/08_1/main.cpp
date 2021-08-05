#include <bits/stdc++.h>

using namespace std;

//================HEAP=============
template<class Etype, class Cmp>
class Heap {
	private:
		int Size;
		Etype *Data;
	public:
		static int MAX_HEAP_SIZE;
		static Etype HEAD_DATA;
		Cmp cp;
		Heap(){
			Size = 0;
			Data = new Etype[MAX_HEAP_SIZE];
			Data[0] = HEAD_DATA; 
		}
		Heap(int size):Size(size) {
			Heap();
		}
		~Heap() {
			delete []Data;
		}

		void Insert(Etype);
		Etype Delete();
		bool empty() {
			return !(Size);
		}
		int size() {
			return Size;
		}
		void PrintTrace(int);
		void Print();
};

template<class Etype, class Cmp>
void Heap<Etype, Cmp>::Insert(Etype X) {
	if (Size) {
		Data[++Size] = X;
		Etype tmp;
		int child, parent;
		child = Size;
		parent = child/2;
		for (;cp(Data[parent], Data[child]);parent = child/2) {
			tmp = Data[parent];
			Data[parent] = Data[child];
			Data[child] = tmp;
			child = parent;
		}
		return;
	} else {
		Data[++Size] = X;
		return;
	}
}


template<class Etype, class Cmp>
void Heap<Etype, Cmp>::PrintTrace(int idx) {
	bool flg = false;
	for (; idx>=1; idx/=2) {
		if (flg) cout << ' ';
		else flg = true;
		cout << Data[idx];
	}
	cout << endl;
}

template<class Etype, class Cmp>
void Heap<Etype, Cmp>::Print() {
	for (int i=1; i<=Size; ++i) {
		cout << Data[i] << ' ';
	}
	cout << endl;
}

template<class Etype, class Cmp>
Etype Heap<Etype, Cmp>::Delete() {
	Etype res;	
	if (Size) {
		res = Data[1];
		Data[1] = Data[Size--];
		if (Size) {
			Etype tmp;
			int parent, child;
			parent = 1;
			while (true) {
				if (parent*2+1 <= Size) 
					child = cp(Data[parent*2], Data[parent*2+1])?parent*2+1:parent*2;
				else if (parent*2 <= Size)
					child = parent*2;
				else return res;
				if (cp(Data[child], Data[parent])) return res;
				tmp = Data[child];
				Data[child] = Data[parent];
				Data[parent] = tmp;
				parent = child;
			}
		}
	}
	return res;
}
typedef struct PATH {
	int s;
	int d;
	int w;
	PATH () {}
	PATH (int S, int D, int W):s(S), d(D), w(W) {}
	PATH (int W):w(W){}
} Gpath;

struct CmpGpathMin {
	bool operator () (const Gpath *a, const Gpath *b) const {
		return a->w > b->w;
	}
};
Gpath minGpath(INT_MIN);
template<> int Heap<Gpath*, CmpGpathMin>::MAX_HEAP_SIZE = 3030;
template<> Gpath* Heap<Gpath*, CmpGpathMin>::HEAD_DATA = &minGpath;
//================HEAP=============

typedef struct NODE {
	int ID;
	int W;
	NODE *Next;
	NODE ():Next(NULL) {}
	NODE (int id, int w, NODE *h):Next(h),ID(id),W(w) {}
} Gnode;

void setIntArray(int *a, int s, int v) {
	for (int i=0; i<s; ++i) {
		a[i] = v;
	}
}

class Solve {
	private:
		Gnode **Graph;
		int V;
		int E;
		int Prim();
		void DeletePath(int a, int b) {
			Gnode *last,*tmp;
			last = tmp = Graph[a];
			while (tmp) {
				if (tmp->ID == b) {
					if (Graph[a] == tmp) Graph[a] = tmp->Next;
					else {
						last->Next = tmp->Next;
					}
					break;
				}
				last = tmp;
				tmp = tmp->Next;	
			}
		}
	public:
		Solve () {
			cin >> V >> E;
			Graph = new Gnode*[V];
			memset(Graph, 0, sizeof(Gnode*)*V);
			int a,b,w;
			for (int i=0; i<E; ++i) {
				cin >> a >> b >> w;
				--a,--b;
				Graph[a] = new Gnode(b, w, Graph[a]); 
				Graph[b] = new Gnode(a, w, Graph[b]); 
			}
		}
		void solve () {
			cout << Prim();
		}
};

int Solve::Prim() {
	int *dist = new int[V];
	setIntArray(dist, V, INT_MAX);
	dist[0] = 0;
	Heap<Gpath*, CmpGpathMin> minPath;
	int CV = 0, cnt = 0, totalCost = 0;
	while (cnt < V-1) {
		Gnode *tmp = Graph[CV];
		Gnode *last = Graph[CV];
		while (tmp) {
			if (!dist[tmp->ID]) {
				if (Graph[CV] == tmp) Graph[CV] = tmp->Next;
				else {
					last->Next = tmp->Next;
				}
				DeletePath(tmp->ID, CV);
			} else {
				minPath.Insert(new Gpath(CV, tmp->ID, tmp->W));
			}
			last = tmp;
			tmp = tmp->Next;
		}
		while (minPath.size()) {
			Gpath *tmpp = minPath.Delete();
			if (dist[tmpp->d] == 0) {
				CV = 0;
				continue;
			}
			DeletePath(tmpp->s, tmpp->d);
			DeletePath(tmpp->d, tmpp->s);
			dist[tmpp->d] = 0;
			CV = tmpp->d;
			++cnt;
			totalCost += tmpp->w;
			break;
		}
		if (minPath.size() == 0 && CV == 0) break;
	}
	if (cnt == V-1) return totalCost;
	return -1;
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