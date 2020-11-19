#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,tmp;
    cin >> n;
    vector<int> dic;
    for(int i=0; i<n; i++){
        cin >> tmp;
        dic.push_back(tmp);
    }
    for(int i=0; i<n; i++){
        if(i == 0){
            cout << (dic[0]+dic[1])/2 << ' ';
        }
        else if(i == (n-1)){
            cout << (dic[i]+dic[i-1])/2 << ' ';
        }
        else{
            cout << (dic[i]+dic[i-1]+dic[i+1])/3 << ' ';
        }
    }
    cout << endl;
    return 0;
}
