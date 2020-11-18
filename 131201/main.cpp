#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n, tmp, mx=0, mxk;
    map<int, int> cnt;
    cin >> n;
    for(int i=0; i<n; i++){
            cin >> tmp;
            map<int,int>::iterator iter;
            iter = cnt.find(tmp);
            if(iter != cnt.end()){
                cnt[tmp] = cnt[tmp] + 1;
            }
            else{
                cnt[tmp]  = 1;
            }
            if(cnt[tmp] > mx){
                mx = cnt[tmp];
                mxk = tmp;
            }
    }
    for(map<int,int>::iterator iter = cnt.begin(); iter != cnt.end(); iter++){
        //cout << iter->first << ' ' << iter->second << endl;
        if(iter->second == mx){
            if(iter ->first < mxk){
                mxk = iter->first;
            }
        }
    }
    cout << mxk << endl;
    return 0;
}
