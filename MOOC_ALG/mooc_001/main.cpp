#include <iostream>
#include <cstring>

using namespace std;

char oriLock[40];
char tarLock[40];
char Lock[40];

bool findRes(bool inPress, int &res){
	res = 0;
	memcpy(Lock, oriLock, sizeof(oriLock));
	int L = strlen(oriLock);
	for(int i=0; i<L; ++i){
		if(inPress){
			++res;
		}
		Lock[i] = inPress^(Lock[i] == '1')?'1':'0';
		if(i<(L-1)){
			Lock[i+1] = inPress^(Lock[i+1] == '1')?'1':'0';
		}
		if(i>0){
			Lock[i-1] = inPress^(Lock[i-1] == '1')?'1':'0';
		}
		inPress = Lock[i] != tarLock[i];
	}
	if(Lock[L-1] == tarLock[L-1])
		return true;
	else
		return false;
}


int main(){
	//freopen("test.txt", "r", stdin);
	cin >> oriLock >> tarLock;
	int res;
	if(findRes(true, res) || findRes(false, res))
	{
		cout << res << endl;
	}
	else
		cout << "impossible" << endl;
	return 0;
}