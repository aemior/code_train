#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test2.txt", "r", stdin);
    long N,m,tmp, T=0,D=0,E=0, last;
    vector<bool> fall;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> m;
        if(m==0){
            fall.push_back(false);
            continue;
        }
        cin >> last;
        bool ffg=false;
        for(int j=1; j<m; j++){
            cin >> tmp;
            if(tmp > 0){
                if(last != tmp){
                    ffg = true;
                }
                last = tmp;
            }
            else{
                last = last + tmp;
            }
        }
        T += last;
        if(ffg){
            D+=1;
        }
        fall.push_back(ffg);
    }
    if(fall.size() == 3){
        if(fall[0] && fall[1] && fall[2]) E=3;
    }
    else if(fall.size() > 3){
        if(fall[0] && fall[fall.size()-1] && fall[1]){
            E+=1;
        }
        if(fall[0] && fall[fall.size()-1] && fall[fall.size()-2]){
            E+=1;
        }
        for(int i=1; i<fall.size()-1; i++){
            if(fall[i-1] && fall[i] && fall[i+1]){
                E+=1;
            }
        }
    }
    cout << T << ' ' << D << ' ' << E << endl;
    return 0;
}
