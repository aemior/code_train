#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,s,t,pi=0,pj=0;
    cin >> n;
    vector<vector<int> > H;
    vector<vector<int> > W;
    for(int i=0; i<n; i++){
        cin >> s >> t;
        vector<int> vt;
        vt.push_back(s);
        vt.push_back(t);
        H.push_back(vt);
    }
    for(int i=0; i<n; i++){
        cin >> s >> t;
        vector<int> vt;
        vt.push_back(s);
        vt.push_back(t);
        W.push_back(vt);
    }
    long long T=0;
    for(;pi <n;pi++){
        for(pj=0;pj<n;pj++){
            if(W[pj][1] < H[pi][0]){
                continue;
            }
            else if(W[pj][0] > H[pi][1]){
                break;
            }
            else{
                vector<int> tp;
                tp.push_back(W[pj][0]);
                tp.push_back(W[pj][1]);
                tp.push_back(H[pi][0]);
                tp.push_back(H[pi][1]);
                sort(tp.begin(), tp.end());
                T = T + (tp[2]-tp[1]);
            }
        }
    }
    cout << T << endl;
    return 0;
}
