#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,tmp;
    vector<vector<int>> ad;
    cin >> n >> m;
    for(int i=0; i< n; i++)
    {
        vector<int> row;
        for(int j=0; j<m; j++){
            cin >> tmp;
            row.push_back(tmp);
        }
        ad.push_back(row);
    }
    for(int j=m-1; j>=0; j--){
        for(int i=0; i<n; i++){
            cout << ad[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
