#include <bits/stdc++.h>

using namespace std;

long loop_time(long state, long t, long long T, vector<long> ryg){
    long sumt = ryg[0] + ryg[1] +ryg[2];
    if(T > sumt) T = T%sumt;
    if(t > T){
        t = t-T;
        if(state == 3) return 0;
        else{
            if(state == 2) return (t+ryg[0]);
            else return t;
        }
    }
    T = T - t;
    if(state == 1){
        state = 3;
    }
    else if(state == 2){
        state = 1;
    }
    else if(state == 3){
        state = 2;
    }
    while(true){
        if(T == 0 || T <= ryg[state-1]) break;
        T = T - ryg[state-1];
        if(state == 1){
            state = 3;
        }
        else if(state == 2){
            state = 1;
        }
        else if(state == 3){
            state = 2;
        }
    }
    if(state == 3){
        return 0;
    }
    else if(state == 2){
        return ryg[1]-T+ryg[0];
    }
    else{
        return ryg[0]-T;
    }
}

int main()
{
    long r,y,g,n,k,t;
    long long T=0;
    freopen("test.txt", "r", stdin);
    cin >> r >> y >> g;
    vector<long> ryg;
    ryg.push_back(r);
    ryg.push_back(y);
    ryg.push_back(g);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k >> t;
        if(k == 0){
            T = T + t;
        }
        else{
            T = T + loop_time(k, t, T, ryg);
        }
        cout << "#DEBUG T> " << T << endl;
    }
    cout << T << endl;
    return 0;
}
