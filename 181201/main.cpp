#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int r,y,g,n,k,t,cnt=0;
    cin >> r >> y >> g >> n;
    for(int i=0; i<n; i++){
        cin >> k >> t;
        if(k==0 || k==1){
            cnt+=t;
        }
        else if(k==2){
            cnt+=t;
            cnt+=r;
        }
    }
    cout << cnt << endl;
    return 0;
}
