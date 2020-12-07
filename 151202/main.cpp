#include <bits/stdc++.h>

using namespace std;

void ptable(vector<vector<int> >& tb_get, int m, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << tb_get[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    freopen("test2.txt", "r", stdin);
    int n,m, tmp;
    vector<vector<int> > table, r_m, c_m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        vector<int> line;
        for(int j=0; j<m; j++){
            cin >> tmp;
            line.push_back(tmp);
        }
        table.push_back(line);
    }
    //ptable(table, m, n);
    int s,e;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            s = j;
            for(e = s+1; e<m; e++){
                if(table[i][s] != table[i][e]) break;
            }
            e = e-1;
            if(e-s >= 2){
                vector<int> tmp_m;
                tmp_m.push_back(i);
                tmp_m.push_back(s);
                tmp_m.push_back(e);
                r_m.push_back(tmp_m);
            }
            j = e;
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            s = j;
            for(e = s+1; e<n; e++){
                if(table[s][i] != table[e][i]) break;
            }
            e = e-1;
            if(e-s >= 2){
                vector<int> tmp_m;
                tmp_m.push_back(i);
                tmp_m.push_back(s);
                tmp_m.push_back(e);
                c_m.push_back(tmp_m);
            }
            j = e;
        }
    }

    for(int i=0; i<r_m.size(); i++){
        for(int j=r_m[i][1]; j<=r_m[i][2]; j++){
            table[r_m[i][0]][j] = 0;
        }
    }
    for(int i=0; i<c_m.size(); i++){
        for(int j=c_m[i][1]; j<=c_m[i][2]; j++){
            table[j][c_m[i][0]] = 0;
        }
    }
    ptable(table, m, n);

    return 0;
}
