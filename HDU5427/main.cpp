#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int T,N,tmp_age;
    string buff;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        map<int, string> tmp_map;
        getline(cin, buff);
        for(int j=0; j<N; j++){
            getline(cin, buff);
            cout << "#DEBUG: " << buff << endl;
            tmp_age = atoi(buff.substr(buff.size()-4,4).c_str());
            tmp_map[tmp_age] = buff.substr(0,buff.size()-5);
        }
        for(map<int, string>::reverse_iterator iter = tmp_map.rbegin();iter!=tmp_map.rend(); iter++ ){
            cout << iter->second << endl;
        }
    }
    return 0;
}
