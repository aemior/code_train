#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n, tmp, mi = 65533;
    vector<int> dic;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        for(int j=0; j<dic.size(); j++){
            if(abs(tmp - dic[j]) < mi){
                mi = abs(tmp - dic[j]);
            }
        }
        dic.push_back(tmp);
    }
    cout << mi << endl;
    return 0;
}
