#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int T,m;
    char ta,tb;
    string MING, XI;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> XI >> MING >> m;
        vector<vector<char>> tab;
        for(int j=0; j<m; j++){
            cin >> ta >> tb;
            tab.push_back({ta,tb});
        }
        bool hap_flg=true, tmp_flg=false;
        for(int j=0,k=0; j<XI.size(); j++){
            tmp_flg=false;
            for(; k<MING.size(); k++){
                if(MING.size()-k < XI.size()-j){
                    tmp_flg = true;
                    break;
                }
                if(MING[k] != XI[j]){
                    tmp_flg = true;
                    for(int o=0; o<tab.size(); o++){
                        if( (MING[k]==tab[o][0]) && (XI[j]==tab[o][1])){
                            tmp_flg = false;
                            k++;
                            break;
                        }
                    }
                    if(!tmp_flg) break;
                }
                else{
                    tmp_flg = false;
                    k++;
                    break;
                }
            }
            if(tmp_flg){
                hap_flg = false;
                break;
            }
        }
        if(hap_flg){
            cout << "Case #" << i+1 << ": happy" << endl;
        }
        else{
            cout << "Case #" << i+1 << ": unhappy" << endl;
        }
    }
    return 0;
}
