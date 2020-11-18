#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,k,tmp, current=0, cnt=0;
    bool cl_flg = true;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> tmp;
        if(cl_flg){
            current = 0;
            cl_flg = false;
            cnt++;
        }
        current = current + tmp;
        if(current >= k){
            cl_flg  = true;
        }
    }
    cout << cnt << endl;
    return 0;
}
