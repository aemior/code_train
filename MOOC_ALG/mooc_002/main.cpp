#include <iostream>
#include <cstring>
#include <map>
#include <string>

using namespace std;

map<int, string> moves = {
{1,"ABDE"},
{2,"ABC"},
{3,"BCEF"},
{4,"ADG"},
{5,"BDEFH"},
{6,"CFI"},
{7,"DEGH"},
{8,"GHI"},
{9,"EFHI"}
};

int oriClocks[9];
int Clocks[9];

void triClock(int i){
	if(Clocks[i] == 3) Clocks[i] = 0;
	else ++Clocks[i];
}

void moveClocks(const int *res, int len){
	for(int i=0; i<len; ++i){
		for(int j=0; j< moves[res[i]+1].length(); ++j){
			triClock(moves[res[i]+1][j] - 'A');
		}
	}
}

bool isOk(){
	for(int i=0; i<9; ++i){
		if(Clocks[i]) return false;
	}
	return true;
}

bool okToUse(const int *res, int target, int len){
	int cnt = 0;
	for(int i=0; i<len; i++){
		if(res[i] == target){
			++cnt;
		}
		if(cnt > 3) return false;
	}
	return true;
}

bool enmOP(int* & res,int curr, int limit){
	int k;
	if(curr > 0){
		k=res[curr-1];
	}
	else{
		k=0;
	}
	if(curr == limit-1){
		for(; k<10; k++){
			//if(okToUse(res, k, curr)) continue;
			res[curr] = k;
			memcpy(Clocks, oriClocks, sizeof(oriClocks));
			moveClocks(res, limit);
			if(isOk()) return true;
		}
		return false;
	}
	else{
		for(;k<10;++k){
			res[curr] = k;
			if(enmOP(res, curr+1, limit)){
				return true;
			}
		}
		return false;
	}
}

int main(){
	freopen("test.txt", "r", stdin);
	for(int i=0; i<9; ++i){
		cin >> oriClocks[i];
	}
	memcpy(Clocks, oriClocks, sizeof(oriClocks));
	if(isOk()) return 0;
	for(int i=1; i<37; i++){
		int *res = new int[i];
		if(enmOP(res, 0, i)){
			for(int j=0; j<i; ++j){
				cout << res[j]+1;
				if(j<(i-1)) cout << ' ';
			}
			cout << endl;
			delete []res;
			break;
		}
		delete []res;
	}
	return 0;
}