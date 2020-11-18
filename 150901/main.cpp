#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,tmp, current=-1, cnt=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        if(tmp != current){
            cnt++;
            current = tmp;
        }
    }
    cout << cnt << endl;
    return 0;
}
