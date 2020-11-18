#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,tmp,g,l;
    vector<int> dic;
    bool ng_flg = false;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        dic.push_back(tmp);
    }
    for(int i=0; i<n; i++){
        g=0;
        l=0;
        for(int j=0; j<n; j++){
            if(dic[j]>dic[i]) g++;
            else if(dic[j]<dic[i]) l++;
        }
        if(g==l){
            cout << dic[i] << endl;
            ng_flg = true;
            break;
        }
    }
    if(!ng_flg){
        cout << -1 << endl;
    }
    return 0;
}
