#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,m;
    cin >> n >> m;
    vector<vector<int> > A,B;
    for(int i=0; i<n; i++){
        int x,y;
        string cls;
        cin >> x >> y >> cls;
        if(cls == "A") A.push_back({x,y});
        else B.push_back({x,y});
    }
    for(int i=0;i<m;i++){
        int t0,t1,t2;
        bool a_g,pflg = false;
        cin >> t0 >> t1 >> t2;
        if(t1*A[0][0]+t2*A[0][1]+t0 > 0) a_g = true;
        else a_g = false;
        for(int k=1; k<A.size(); k++){
            if(a_g){
                if(t1*A[k][0]+t2*A[k][1]+t0 <= 0){
                    cout << "No" << endl;
                    pflg = true;
                    break;
                }
            }
            else{
                if(t1*A[k][0]+t2*A[k][1]+t0 >= 0){
                    cout << "No" << endl;
                    pflg = true;
                    break;
                }

            }
        }
        if(pflg) continue;
        for(int k=1; k<B.size(); k++){
            if(a_g){
                if(t1*B[k][0]+t2*B[k][1]+t0 >= 0){
                    cout << "No" << endl;
                    pflg = true;
                    break;
                }
            }
            else{
                if(t1*B[k][0]+t2*B[k][1]+t0 <= 0){
                    cout << "No" << endl;
                    pflg = true;
                    break;
                }
            }
        }
        if(pflg) continue;
        cout << "Yes" << endl;
    }
    return 0;
}
