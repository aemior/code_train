#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test2.txt", "r", stdin);
    int n,tmp;
    vector<vector<int> > mats;
    cin >> n;
    if(n == 1){
        cin >> tmp;
        cout << tmp;
        return 0;
    }
    for(int i=0; i<n; i++){
        vector<int> line;
        for(int j=0; j<n; j++){
            cin >> tmp;
            line.push_back(tmp);
        }
        mats.push_back(line);
    }
    int idx=1;
    bool up=true;
    for(;idx<=n; idx++){
        if(up){
            for(int y=idx-1,x=0; y>=0; x++,y--){
                cout << mats[y][x] << ' ';
            }
            up = false;
        }
        else{
            for(int x=idx-1,y=0; x>=0; x--,y++){
                cout << mats[y][x] << ' ';
            }
            up = true;
        }
    }
    idx = idx-2;
    for(;idx>0; idx--){
        if(up){
            for(int y=n-1,x=n-idx; x<n; x++,y--){
                cout << mats[y][x] << ' ';
            }
            up = false;
        }
        else{
            for(int x=n-1,y=n-idx; y<n; x--,y++){
                cout << mats[y][x] << ' ';
            }
            up = true;
        }

    }
    cout << endl;
    return 0;
}
