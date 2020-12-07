#include <bits/stdc++.h>

using namespace std;

void ptable(vector<vector<int> > &tb_get){
    cout << "==========================" << endl;
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<10; j++)
            cout << tb_get[i][j] << ' ';
        cout << endl;
    }
    cout << "==========================" << endl;
}

void pgtable(vector<vector<int> > tb_get, vector<vector<int> > &sp_get, int px, int py){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++){
            if((px+j) >=10 || (py+i) >=15) continue;
            tb_get[py+i][px+j] = tb_get[py+i][px+j] + sp_get[i][j];
        }
    ptable(tb_get);
}

int main()
{
    freopen("test.txt", "r", stdin);
    vector<vector<int> > table, shap;
    int tmp,px,py;
    for(int i=0; i<15; i++){
        vector<int> ttb;
        for(int j=0; j<10; j++){
            cin >> tmp;
            ttb.push_back(tmp);
        }
        table.push_back(ttb);
    }
    for(int i=0; i<4; i++){
        vector<int> ttb;
        for(int j=0; j<4; j++){
            cin >> tmp;
            ttb.push_back(tmp);
        }
        shap.push_back(ttb);
    }
    cin >> px;
    px = px-1;
    vector<int> bottm;
    for(int i=0; i<4; i++){
        bool eflg = true;
        for(int j=3; j>=0; j--){
            if(shap[j][i]){
                eflg = false;
                bottm.push_back(j);
                break;
            }
        }
        if(eflg) bottm.push_back(-1);
    }
    bool btflg = false;
    for(py=0;py<15;py++){
        //pgtable(table, shap, px, py);
        for(int i=0; i<4; i++){
            if(bottm[i] == -1) continue;
            else{
                if(py+bottm[i]+1 == 15){
                    btflg = true;
                    break;
                }
                else if(table[py+bottm[i]+1][px+i]){
                    btflg = true;
                    break;
                }
            }
        }
        if(btflg) break;
    }
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++){
            if((px+j) >=10 || (py+i) >=15) continue;
            table[py+i][px+j] = table[py+i][px+j] + shap[i][j];
        }
    for(int i=0; i<15; i++){
        for(int j=0; j<10; j++){
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
