#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    string T;
    cin >> T;
    if(T.size()<3){
        cout << T << endl;
    }
    else{
        bool back_flg;
        int f_p=0,b_p=T.size()-1;
        string ostr;
        if(T.size()%2 == 0) back_flg = true;
        else back_flg = false;
        while(f_p != b_p){
            if(back_flg){
                ostr+=T[b_p];
                b_p--;
                back_flg = false;
            }
            else{
                ostr+=T[f_p];
                f_p++;
                back_flg = true;
            }
        }
        ostr+=T[f_p];
        for(int i=ostr.size()-1;i>=0; i--) cout << ostr[i];
        cout << endl;
    }
    return 0;
}
