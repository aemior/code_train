#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,L,t,tmp;
    vector<int> poss;
    vector<bool> vcss;
    cin >> n >> L >> t;
    for(int i=0; i<n; i++){
        cin >> tmp;
        poss.push_back(tmp);
        vcss.push_back(true);
    }
    for(int T=0; T<t; T++){
        for(int i=0; i<n; i++){
            if(vcss[i]){
                poss[i] = poss[i] + 1;
            }
            else{
                poss[i] = poss[i] - 1;
            }
        }
        for(int i=0; i<n; i++){
            if(vcss[i]){
                if(poss[i] == L) vcss[i] = false;
                else{
                    for(int j=0; j<n; j++){
                        if(poss[i] == poss[j]){
                            if(i != j){
                                vcss[i] = false;
                                break;
                            }
                        }
                    }
                }
            }
            else{
                if(poss[i] == 0) vcss[i] = true;
                else{
                    for(int j=0; j<n; j++){
                        if(poss[i] == poss[j]){
                            if(i != j){
                                vcss[i] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << poss[i] << ' ';
    }
    cout << endl;
    return 0;
}
