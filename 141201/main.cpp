#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,tmp;
    map<int,int> dic;
    cin >> n;
    for(int i=0; i<n; i++){
            cin >> tmp;
            map<int,int>::iterator iter =  dic.find(tmp);
            if(iter == dic.end()){
                dic[tmp] = 1;
            }
            else{
                dic[tmp] = dic[tmp] + 1;
            }
            cout << dic[tmp] << ' ';

    }
    cout << endl;
    return 0;
}
