#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int N,K,w,s,c;
    vector<int> kbx;
    vector<vector<int> > kinf;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        kbx.push_back(i+1);
    }
    for(int i=0; i<K; i++){
        cin >> w >> s >> c;
        int tmp[] = {w,s,c};
        vector<int> tif(tmp, tmp+sizeof(tmp)/sizeof(int));
        kinf.push_back(tif);
    }
    set<int> all_t;
    for(int i=0; i<K; i++){
        all_t.insert(kinf[i][1]);
        all_t.insert(kinf[i][1]+kinf[i][2]);
    }
    for(set<int>::iterator it=all_t.begin(); it!=all_t.end(); it++){
        vector<int> bk,gt;
        for(int i=0; i<K; i++){
            if(kinf[i][1]+kinf[i][2] == *it) bk.push_back(kinf[i][0]);
            else if(kinf[i][1] == *it) gt.push_back(kinf[i][0]);
        }
        sort(bk.begin(), bk.end());
        for(int i=0; i<bk.size(); i++){
            for(int j=0; j<kbx.size(); j++){
                if(kbx[j] == 0){
                    kbx[j] = bk[i];
                    break;
                }
            }
        }
        for(int i=0; i<gt.size(); i++){
            for(int j=0; j<kbx.size(); j++){
                if(kbx[j] == gt[i]){
                    kbx[j] = 0;
                    break;
                }
            }
        }
        /*
        cout << "#DEBUG> " << *it <<  "< ";
        for(int i=0; i<N; i++){
        cout << kbx[i] << ' ';
        }
        cout << endl;
        */
    }
    for(int i=0; i<N; i++){
        cout << kbx[i] << ' ';
    }
    cout << endl;
    return 0;
}
