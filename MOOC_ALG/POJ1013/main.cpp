#include <iostream>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

int main(){
	//freopen("test.txt", "r", stdin);
	int n;
	string tmp,FLG;
	cin >> n;
	bool HeavyFlg[12];
	bool LightFlg[12];
	bool ShowFlg[12];
	for(int i=0; i<n; ++i){
		vector<string> buf;
		memset(HeavyFlg, true, 12);
		memset(LightFlg, true, 12);
		memset(ShowFlg, false, 12);
		for(int j=0; j<9; ++j){
			cin >> tmp;
			buf.push_back(tmp);
		}
		for(int j=2; j<9; j+=3){
			if(buf[j] == "even"){
				for(int k=1; k<=2; ++k){
					for(int m=0; m<4; ++m){
						HeavyFlg[buf[j-k][m] - 'A'] = false;
						LightFlg[buf[j-k][m] - 'A'] = false;
						ShowFlg[buf[j-k][m] - 'A'] = true;
					}
				}
			}
			if(buf[j] == "up" || buf[j] == "down"){
				int o,p;
				if(buf[j] == "up"){
					o=1;p=2;
				}
				else{
					o=2;p=1;
				}
				for(int m=0; m<4; ++m){
					LightFlg[buf[j-p][m] - 'A'] = LightFlg[buf[j-2][m] - 'A'] & true;
					HeavyFlg[buf[j-p][m] - 'A'] = false;
					ShowFlg[buf[j-p][m] - 'A'] = true;
				}
				for(int m=0; m<4; ++m){
					HeavyFlg[buf[j-o][m] - 'A'] = HeavyFlg[buf[j-1][m] - 'A'] & true;
					LightFlg[buf[j-o][m] - 'A'] = false;
					ShowFlg[buf[j-o][m] - 'A'] = true;
				}
			}
		}
		for(int j=0; j<12; ++j){
			if(ShowFlg[j]){
				if(HeavyFlg[j]){
					cout << char('A'+j);
					FLG = "heavy.";
				}
				if(LightFlg[j]){
					cout << char('A'+j);
					FLG = "light.";
				}
			}
		}
		cout << " is the counterfeit coin and it is " << FLG;
	}
	
}

