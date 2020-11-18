#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int N, tmp, cnt =0;
    set<int> dic;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        set<int>::iterator iter = dic.find(-tmp);
        if(iter != dic.end()) cnt++;
        dic.insert(tmp);
    }
    cout << cnt << endl;
    return 0;
}
