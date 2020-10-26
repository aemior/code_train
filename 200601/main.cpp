#include <bits/stdc++.h>

using namespace std;

struct samp{
    int x;
    int y;
    string lb;
};

int main()
{
    freopen("test.txt", "r", stdin);
    int n,m;
    cin >> n >> m;
    vector<samp> test_set;
    for(int i=0; i<n; i++){
        samp s1;
        cin >> s1.x >> s1.y >> s1.lb;
        test_set.push_back(s1);
    }
    for(int i=0;i<m;i++){
        int t0,t1,t2;
        bool a_g=false,pflg = false;
        cin >> t0 >> t1 >> t2;
        if(test_set[0].x*t1+test_set[0].y*t2+t0 > 0){
            if(test_set[0].lb == "A") a_g = true;
        }
        else if(test_set[0].x*t1+test_set[0].y*t2+t0 < 0){
            if(test_set[0].lb == "B") a_g = true;
        }
        else{
            cout << "No" << endl;
            continue;
        }
        for(int j=1;j<test_set.size(); j++){
            int tmp = test_set[j].x*t1 + test_set[j].y*t2 + t0;
            if(tmp == 0){
                cout << "No" << endl;
                pflg = true;
            }
            if(test_set[j].lb == "A"){
                if(a_g){
                    if(tmp < 0) pflg = true;
                }
                else{
                    if(tmp > 0) pflg = true;
                }
                if(pflg){
                    cout << "No" << endl;
                    break;
                }
            }
            if(test_set[j].lb == "B"){
                if(a_g){
                    if(tmp > 0) pflg = true;
                }
                else{
                    if(tmp < 0) pflg = true;
                }
                if(pflg){
                    cout << "No" << endl;
                    break;
                }
            }

        }
        if(pflg) continue;
        cout << "Yes" << endl;
    }
    return 0;
}
