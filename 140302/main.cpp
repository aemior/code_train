#include <bits/stdc++.h>

using namespace std;


int main()
{
    freopen("test.txt", "r", stdin);
    int N,M,tmp, x1,y1,x2,y2;
    vector<vector<int> > infs;
    vector<int> pos;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        vector<int> wd;
        for(int j=0; j<4; j++){
            cin >> tmp;
            wd.push_back(tmp);
        }
        wd.push_back(i+1);
        infs.push_back(wd);
        pos.push_back(i);
    }
    /*
    cout << "#DEBUG> ";
        for(int j=N-1; j>=0; j--){
            cout << pos[j] << ' ';
        }
    cout << endl;
    */
    for(int i=0; i<M; i++){
        cin >> x1 >> y1;
        bool igflg = true;
        for(int j=N-1; j>=0; j--){
            if(infs[pos[j]][0] <= x1 && x1 <= infs[pos[j]][2]){
                if(infs[pos[j]][1] <= y1 && y1 <= infs[pos[j]][3]){
                    igflg = false;
                    cout << infs[pos[j]][4] << endl;
                    for(int k=j; k<(N-1); k++){
                        tmp = pos[k+1];
                        pos[k+1] = pos[k];
                        pos[k] = tmp;
                    }
                    break;
                }
            }
        }
        if(igflg) cout << "IGNORED" << endl;
        /*
        cout << "#DEBUG> ";
        for(int j=N-1; j>=0; j--){
            cout << pos[j] << ' ';
        }
        cout << endl;
        */
    }
    return 0;
}
