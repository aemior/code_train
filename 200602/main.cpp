#include <bits/stdc++.h>

using namespace std;


int main()
{
    freopen("test.txt", "r", stdin);
    long long n,a,b,tp,tv,tmax;
    map<int, int> va;
    cin >> n >> a >> b;
    if(b == 0){
        cout << "0" << endl;
        return 0;
    }
    for(int i=0; i<a; i++){
            cin >> tp >> tv;
            va[tp] = tv;
    }
    tmax = tp;
    long long res=0;
    for(int i=0; i<b; i++){
            cin >> tp >> tv;
            if(tp > tmax) break;
            map<int, int>::iterator iter = va.find(tp);
            if(iter != va.end()){
                res = iter->second*tv + res;
            }
    }
    cout << res << endl;
    return 0;
}
