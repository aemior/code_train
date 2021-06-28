#include <iostream>
#include <cstring>

using namespace std;

char buf[3][3][7];

bool isFake(char c, bool light){
	for(int i=0; i<3; ++i){
		char *Pleft, *Pright;
		if(light){
			Pleft = buf[i][0];
			Pright = buf[i][1];
		}
		else{
			Pleft = buf[i][1];
			Pright = buf[i][0];
		}
		switch (buf[i][2][0])
		{
		case 'u':
			if(strchr(Pright, c) == NULL){
				return false;
			}
			break;
		case 'e':
			if(strchr(Pleft, c) || strchr(Pright, c)){
				return false;
			}
			break;
		case 'd':
			if(strchr(Pleft, c) == NULL){
				return false;
			}
			break;
		}
	}
	return true;
};

int main(){
	freopen("test.txt", "r", stdin);
	int n,t;
	cin >> n;
	while(n--){
		for(t=0;t<3;t++) cin >> buf[t][0] >> buf[t][1] >> buf[t][2];
		for(char i='A';i<='L';++i){
			if(isFake(i, true)){
				cout << i << " is the counterfeit coin and it is light.\n";
				break;
			}
			else if(isFake(i, false)){
				cout << i << " is the counterfeit coin and it is heavy.\n";
				break;
			}
		}
	}
	return 0;
}