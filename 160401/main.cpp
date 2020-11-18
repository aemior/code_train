#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, last, tmp, cnt=0;
    bool in_flg, tmp_flg;
    cin >> n >> last;
    for(int i=1; i<n; i++){
        cin >> tmp;
        tmp_flg = (tmp > last);
        if(i>1){
            if(tmp_flg != in_flg){
                cnt++;
            }
        }
        in_flg = tmp_flg;
        last = tmp;
    }
    cout << cnt << endl;
    return 0;
}
