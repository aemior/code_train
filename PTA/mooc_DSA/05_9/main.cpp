#include <bits/stdc++.h>

using namespace std;

typedef struct hfNODE* HFtree;
typedef struct hfNODE HFNODE;

struct hfNODE {
	char val;
	int weight;
	hfNODE *left;
	hfNODE *right;
	hfNODE(){
		val = 0;
		left = right = NULL;
	}
	hfNODE(int w):weight(w){
		val = 0;
		left = right = NULL;
	}
	hfNODE(char v):val(v) {
		left = right = NULL;
	}
	hfNODE(char v, int w):val(v), weight(w){
		left = right = NULL;
	}
	bool operator < (const hfNODE &b) const {
		return this->weight < b.weight;
	}
	bool operator > (const hfNODE &b) const {
		return this->weight > b.weight;
	}
};

int preTrval(HFtree root, int level) {
	if (root) {
		return preTrval(root->left, level+1) + preTrval(root->right, level+1)
		       + (root->val?root->weight*level:0);
	}
	return 0;
}

int getWPL(HFtree root) {
	return preTrval(root, 0);
} 

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

/*
template<class Etype>
struct CmpHeapMin {
	bool operator () (const Etype &a, const Etype &b) const{
		return a>b;
	}
};
template<class Etype>
struct CmpHeapMax {
	bool operator () (const Etype &a, const Etype &b) const {
		return a<b;
	}
};
*/
struct CmpHFtreeMin {
	bool operator () (const HFtree &a, const HFtree &b) const {
		return a->weight > b->weight;
	}
};

class HFcheck {
	private:
		map<char, int> Dic;
		int optimalWPL;
	public:
		void readDic() {
			char key;
			int val;
			cin >> key >> val;
			Dic[key] = val;
		}
		void getOptimalWPL () {
			HFNODE buff[1000];
			Heap<HFtree, CmpHFtreeMin > heap;
			int s=0;
			for (auto it = Dic.begin(); it != Dic.end(); ++it, ++s) {
				buff[s] = HFNODE(it->first, it->second);
				heap.Insert(&buff[s]);
			}
			while (heap.size() >= 2) {
				auto t1 = heap.Delete();
				auto t2 = heap.Delete();
				HFNODE mid(t1->weight+t2->weight);
				mid.left = t1;
				mid.right = t2;
				buff[s] = mid;
				heap.Insert(&buff[s]);
				s++;
			}
			auto HFroot = heap.Delete();
			optimalWPL = getWPL(HFroot);
		}
		void checkCODE() {
			char key;
			string tmp;
			vector<string> buff;
			int WPL=0;
			for (int i=0; i<Dic.size(); ++i) {
				cin >> key >> tmp;
				WPL += Dic[key] * tmp.size();
				buff.push_back(tmp);
			}
			if (WPL > optimalWPL) {
				cout << "No" << endl;
				return;
			} else {
				for (int i=0; i<buff.size(); ++i) {
					for (int j=0; j<buff.size(); ++j) {
						if (i != j &&
						    buff[j].find(buff[i]) < buff[j].length() &&
							!(buff[j].find(buff[i]))) {
								cout << "No" << endl;
								return;
							}
					}
				}
				cout << "Yes" << endl;
				return;
			}
		}
};

HFNODE minHFnode(-30000);
template<> int Heap<HFtree, CmpHFtreeMin>::MAX_HEAP_SIZE = 64;
template<> HFtree Heap<HFtree, CmpHFtreeMin>::HEAD_DATA = &minHFnode;

int main (int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);
	int N, M;
	HFcheck Teller;
	cin >> N;
	while (N--) {
		Teller.readDic();
	}
	Teller.getOptimalWPL();
	cin >> M;
	while (M--)
	{
		Teller.checkCODE();
	}
	return 0;
}