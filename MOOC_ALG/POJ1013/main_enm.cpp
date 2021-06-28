#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	freopen("test.txt", "r", stdin);
	int n,a,b;
	cin >> n;
	string tmp,FLG;
	bool pass;
	for(int i=0; i<n; ++i){
		vector<string> buf;
		for(int j=0; j<9; ++j){
			cin >> tmp;
			buf.push_back(tmp);
		}
		for(int j=0; j<12; ++j){
			if('A'+j == 'K'){
				cout << "#DEBUG" << endl;
			}
				bool debug_1 = false < true;
				bool debug_2 = true < false;
			pass = true;
			FLG = "heavy.";
			for(int k=2; k<9; k+=3){
				bool r = strchr(buf[k-1].c_str(), 'A'+j) == NULL,
					l = strchr(buf[k-2].c_str(), 'A'+j) == NULL;
				pass = pass && ((l>r && buf[k] == "up") ||
								(l==r && buf[k] == "even")||
								(l<r && buf[k] == "down"));
				if(!pass) break;
			}
			if(pass){
				cout << char('A'+j);
				break;
			}
			pass = true;
			FLG = "light.";
			for(int k=2; k<9; k+=3){
				bool r = strchr(buf[k-1].c_str(), 'A'+j) == NULL,
					l = strchr(buf[k-2].c_str(), 'A'+j) == NULL;
				pass = pass && ((l<r && buf[k] == "up") ||
								(l==r && buf[k] == "even")||
								(l>r && buf[k] == "down"));
				if(!pass) break;
			}
			if(pass){
				cout << char('A'+j);
				break;
			}
		}
		cout << " is the counterfeit coin and it is " << FLG;
	}
	return 0;
}