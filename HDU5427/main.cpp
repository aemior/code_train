#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int T,N,tmp_age;
    string tmp_name;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        map<int, string> tmp_map;
        for(int j=0; j<N; j++){
            cin >>tmp_name >> tmp_age;
            tmp_map[tmp_age] = tmp_name;
        }
        for(map<int, string>::reverse_iterator iter = tmp_map.rbegin();iter!=tmp_map.rend(); iter++ ){
            cout << iter->second << endl;
        }
    }
    return 0;
}
