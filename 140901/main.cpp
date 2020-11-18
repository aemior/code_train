#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n, tmp, cnt=0, res;
    vector<int> dic;
    cin >> n;
    for(int i=0; i<n; i++){
            cin >> tmp;
            for(int j=0; j<dic.size(); j++){
                res = dic[j]-tmp;
                if(res == 1 || res == -1){
                    cnt++;
                }
            }
            dic.push_back(tmp);
    }
    cout << cnt << endl;
    return 0;
}
