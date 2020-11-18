#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,tmp, last, t_max=0, res;
    cin >> n >> last;
    for(int i=1; i<n; i++){
        cin >> tmp;
        res = last-tmp;
        if(res < 0){
            res = -res;
        }
        if(res > t_max) t_max=res;
        last = tmp;
    }
    cout << t_max << endl;
    return 0;
}
