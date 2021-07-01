#include <iostream>
#include <cstring>
#include <map>
#include <string>

using namespace std;

const char *moves[9] = {
"ABDE",
"ABC",
"BCEF",
"ADG",
"BDEFH",
"CFI",
"DEGH",
"GHI",
"EFHI"
};


int oriClocks[9];
int Clocks[9];
int res[9] = {5,5,5,5,5,5,5,5,5};

class enmMove{
	public:
		int M[9];
		enmMove(){
			for (int i=0; i<9; ++i) {
				M[i] = 0;
			}
		}
		bool n(){
			int op = 1;
			int tc;
			for (int i=0; i<9; ++i) {
				tc = M[i] + op;
				if (tc > 3) {
					op = 1;
					M[i] = 0;
				}
				else {
					M[i] = tc;
					return true;
				}
			}
			if (op) {
				return false;
			}
			return true;
		}
};


void triClock(int i){
	if(Clocks[i] == 3) Clocks[i] = 0;
	else ++Clocks[i];
}

void moveClocks(const int *res){
	for(int i=0; i<9; ++i){
		for(int j=0; j<res[i]; ++j){
			for(int k=0; moves[i][k]; ++k)
				triClock(moves[i][k] - 'A');
		}
	}
}

void setRes(const enmMove &ms){
	memcpy(Clocks, oriClocks, sizeof(oriClocks));
	moveClocks(ms.M);
	int CNT = 0;
	int newCNT = 0;
	for (int i=0; i<9; ++i) {
		CNT += res[i];
		newCNT += ms.M[i];
		if (Clocks[i]) {
			return;
		}
	}
	if (newCNT < CNT) {
		memcpy(res, ms.M, sizeof(res));
	}
}

int main(){
	//freopen("test.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	for(int i=0; i<9; ++i){
		cin >> oriClocks[i];
	}
	enmMove e;
	do {
		setRes(e);
	} while (e.n());
	for (int i=0; i<9; ++i) {
		for (int j=0; j<res[i]; j++) {
			cout << i+1 << ' ';
		}
	}
	return 0;
}