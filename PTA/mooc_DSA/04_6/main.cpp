#include <bits/stdc++.h>

using namespace std;

class CBST{
	private:
		int Data[1010];
		int Size;
	public:
		CBST() {
			memset(Data, 0, sizeof(Data));
			Size = 0;
		}
		void readData(int n);
		void Print() {
			for (int i=0; i<Size; ++i) {
				if (i) cout << ' ';
				cout << Data[i];
			}
		}
		void fillTree(int a, int b, int r, int *bf);
};

void CBST::fillTree(int a, int b, int r, int *bf) {
	if (a > b+1) {
		return;
	} else if (a >= b) {
		Data[r] = *(bf + a);
		return;
	}
	int s = b - a + 1;
	int h = 1 + (int)log2((float)s);
	int lh = h - 1;
	int x = s - (pow(2, lh) - 1);
	int maxx = pow(2, lh - 1);
	int ls = (pow(2, lh - 1) - 1) + (x<maxx?x:maxx);
	Data[r] = *(bf+a+ls);
	fillTree(a, a+ls-1, 2*r+1, bf);
	fillTree(a+ls+1, b, 2*r+2, bf);
}

void CBST::readData(int n) {
	Size = n;
	int *Buffer = new int[n];
	for (int i=0; i<n; ++i) {
		cin >> Buffer[i];
	}
	sort(Buffer, Buffer+Size);
	fillTree(0, Size-1, 0, Buffer);
}

int main (int argc, char *argv[]) {
	freopen(argv[1], "r", stdin);
	int N;
	cin >> N;
	CBST cbst;
	cbst.readData(N);
	cbst.Print();
	return 0;
}