#include <iostream>
#include <cstring>

using namespace std;

unsigned char oriLights[5];
unsigned char Lights[5];
unsigned char Switch[5];

void setBits(unsigned char & c, bool b, int i){
	unsigned char s=0x1;
	s = s << i;
	if(b){
		c = c | s;
	}
	else{
		c = c & ~s;
	}
}

bool getBits(unsigned char c, int i){
	if(c>>i & 0x1){
		return 1;
	}
	else
		return 0;
}

void OutputRes(int i){
	cout << "PUZZLE #" << i+1 << endl;
	for(int m=0; m<5; ++m){
		for(int n=0; n<6; ++n){
			cout << getBits(Switch[m], n);
			if(n < 5) cout << ' ';
		}
		cout << endl;
	}
}

void flipBits(unsigned char &c, int i){
	c ^= (1 << i);
}


int main(){
	freopen("test.txt", "r", stdin);
	int M;
	bool tmp;
	cin >> M;
	for(int i=0; i<M; ++i){
		for(int o=0; o<5; ++o){
			for(int p=0; p<6; ++p){
				cin >> tmp;
				setBits(oriLights[o], tmp, p);
			}
		}
		for(unsigned char fl=0; fl<=0x3f; ++fl){
			memcpy(Lights, oriLights, 5);
			unsigned char switchs = fl;
			for(int L=0; L<5; ++L){
				Switch[L] = switchs;
				if(L<4)
					Lights[L+1] ^= switchs;
				for(int C=0; C<6; ++C){
					if(getBits(switchs, C)){
						flipBits(Lights[L], C);
						if(C>0){
							flipBits(Lights[L], C-1);
						}
						if(C<5){
							flipBits(Lights[L], C+1);
						}
					}
				}
				switchs = Lights[L];
			}
			if(Lights[4] == 0)
				OutputRes(i);
		}
	}
	return 0;
}