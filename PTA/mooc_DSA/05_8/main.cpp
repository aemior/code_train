#include <bits/stdc++.h>

using namespace std;

class TreeSet
{
	private:
		int *Links;
		int Size;
	public:
		TreeSet(int MaxSize) {
			Size = MaxSize;
			if (Size) {
				Links = new int[MaxSize];
				memset(Links, -1, sizeof(int)*Size);
			}
		}
		~TreeSet() {
			if (Size)
				delete []Links;
		}
		int getRoot(int idx) {
			while (Links[idx] >= 0) {
				idx = Links[idx];
			}
			return idx;
		}
		void Insert(int a, int b) {
			int Ra, Rb;
			Ra = getRoot(a-1);
			Rb = getRoot(b-1);
			if (Ra != Rb) {
				if (Links[Ra] < Links[Rb]) {
					Links[Rb] += Links[Ra];
					Links[Ra] = b-1;
				} else {
					Links[Ra] += Links[Rb];
					Links[Rb] = a-1;
				}
			}
		}
		void Check(int a, int b) {
			if (getRoot(a-1) == getRoot(b-1)) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
		void Res() {
			int cnt=0;
			for (int i=0; i<Size; ++i) {
				if (Links[i] < 0) ++cnt;
			}
			if (cnt == 1) cout << "The network is connected." << endl;
			else cout << "There are " << cnt << " components." << endl;
		}
		bool ReadCMD() {
			char c;
			int a,b;
			cin >> c >> a >> b;
			switch (c)
			{
			case 'I':
				Insert(a, b);
				return true;
				break;
			case 'C':
				Check(a, b);
				return true;
				break;
			case 'S':
				Res();
				return false;
				break;
			default:
				return false;
				break;
			}
			return false;
		}
};


int main () {
	//freopen("test_2.txt", "r", stdin);
	int N;
	cin >> N;
	TreeSet networks(N);
	while (networks.ReadCMD());
	return 0;
}