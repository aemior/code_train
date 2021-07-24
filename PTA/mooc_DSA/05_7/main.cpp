#include <bits/stdc++.h>

using namespace std;


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

template<class Etype>
struct CmpHeapMin {
	bool operator () (const Etype &a, const Etype &b) const{
		return a>b;
	}
};
template<class Etype>
struct CmpHeapMax {
	bool operator () (const Etype &a, const Etype &b) {
		return a<b;
	}
};

template<> int Heap<int, CmpHeapMin<int> >::MAX_HEAP_SIZE = 30000;
template<> int Heap<int, CmpHeapMin<int> >::HEAD_DATA = -30000;

int main () {
	//freopen("test.txt", "r", stdin);
	int N, M, tmp;
	cin >> N >> M;
	Heap<int, CmpHeapMin<int> > myheap;
	while (N--) {
		cin >> tmp;
		myheap.Insert(tmp);
	}
	//myheap.Print();
	while (M--) {
		cin >> tmp;
		myheap.PrintTrace(tmp);
	}
	return 0;
}