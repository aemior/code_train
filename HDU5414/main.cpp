#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
char s[N], t[N];

int ref(){
    int T, i, j;
    freopen("test.txt", "r", stdin);
    bool same;
    scanf("%d", &T);
    while(T--){
        scanf("%s%s", &s, &t);
        same = true;
        for(i=j=0; t[i] != '\0'; i++){
            if(same && t[i] == t[0] && s[i] != t[0]){
                break;
            }
            if(t[i] != t[0]){
                same = false;
            }
            if(s[j] != '\0' && t[i] == s[j]){
                j++;
            }
        }
        if(s[j] == '\0' && t[i] == '\0'){
            cout << "Yes_" << endl;
        }
        else{
            cout << "No_" << endl;
        }
    }
    fclose(stdin);
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("test.txt", "r", stdin);
    int T;
    string SA, SB;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> SA >> SB;
        int sub_cnt = SB.size()-SA.size(), j=0, k=0;
        bool pass_flg = true, same_flg = true;
        for(; k<SA.size();){
            if(SA[k] != SB[j]){
                if(sub_cnt == 0 || k==0 || (same_flg && SA[k-1] == SB[j])){
                    pass_flg = false;
                    break;
                }
                else{
                    if(SA[k-1]!=SB[j]) same_flg = false;
                    sub_cnt--;
                    j++;
                }
            }
            else{
                if(SA[k]!=SA[0]) same_flg = false;
                j++;
                k++;
            }
        }
        if(sub_cnt != 0 && same_flg && SA[k-1] == SB[j]){
            pass_flg = false;
        }
        if(pass_flg) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    fclose(stdin);
    cout << "====================" << endl;
    ref();
    return 0;
}




