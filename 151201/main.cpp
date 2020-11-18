#include <bits/stdc++.h>

using namespace std;

int main()
{
    long m,sh=1,k=0, t1;
    cin >> m;
    while(sh <= m){
        t1 = m%(sh*10);
        k = k + t1/sh;
        cout << t1/sh << endl;
        sh = sh * 10;
    }
    if(k==0) k=k+m;
    cout << k << endl;
    return 0;
}
