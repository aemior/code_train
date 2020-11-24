#include <bits/stdc++.h>

using namespace std;


int level(char getopt){
    if(getopt == '+'||getopt == '-') return 0;
    else return 1;
}

int cal(int num1, char ope, int num2){
    if(ope == '+') return num1+num2;
    if(ope == '-') return num1-num2;
    if(ope == 'x') return num1*num2;
    if(ope == '/') return num1/num2;
}
int main()
{
    freopen("test.txt", "r", stdin);
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        char tmp[10];
        cin >> tmp;
        int idx[3] = {0,1,2};
        int idd[3] = {1,3,5};
        if(level(tmp[3]) > level(tmp[1])){
            idx[0] = 1;
            idx[1] = 0;
            if(level(tmp[5]) > level(tmp[1])){
                idx[1] = 2;
                idx[2] = 0;
            }
        }
        else if(level(tmp[5]) > level(tmp[3])){
            idx[1] = 2;
            idx[2] = 1;
            if(level(tmp[5]) > level(tmp[1])){
                idx[0] = 2;
                idx[1] = 0;
            }
        }
        else if(level(tmp[5]) > level(tmp[1])){
            idx[0] = 2;
            idx[1] = 0;
            idx[2] = 1;
        }
        else if(level(tmp[5]) > level(tmp[3])){
            idx[2] = 1;
            idx[1] = 2;
        }
        /*
        cout << "===========" << tmp << endl;
        for(int j=0; j<3; j++){
            cout << idx[j] << ' ';
        }
        cout << endl << "=============" << endl;*/
        int re=0;
        re = cal(tmp[idd[idx[0]]-1]-'0', tmp[idd[idx[0]]], tmp[idd[idx[0]]+1]-'0');
        if(idd[idx[0]] == 1){
            if(idd[idx[1]] == 5){
                int t_re = cal(tmp[idd[idx[1]]-1]-'0', tmp[idd[idx[1]]], tmp[idd[idx[1]]+1]-'0');
                re = cal(re, tmp[idd[idx[2]]], t_re);
            }
            else{
                re = cal(re, tmp[idd[idx[1]]], tmp[idd[idx[1]]+1]-'0');
                re = cal(re, tmp[idd[idx[2]]], tmp[idd[idx[2]]+1]-'0');
            }
        }
        else if(idd[idx[0]] == 3){
            if(idd[idx[1]] == 5){
                re = cal(re, tmp[idd[idx[1]]], tmp[idd[idx[1]]+1]-'0');
                re = cal(tmp[idd[idx[2]]-1]-'0', tmp[idd[idx[2]]], re);
            }
            else{
                re = cal(tmp[idd[idx[1]]-1]-'0', tmp[idd[idx[1]]], re);
                re = cal(re, tmp[idd[idx[2]]], tmp[idd[idx[2]]+1]-'0');
            }
        }
        else{
            if(idd[idx[1]] == 1){
                int t_re = cal(tmp[idd[idx[1]]-1]-'0', tmp[idd[idx[1]]], tmp[idd[idx[1]]+1]-'0');
                re = cal(re, tmp[idd[idx[2]]], t_re);
            }
            else{
                re = cal(tmp[idd[idx[1]]-1]-'0', tmp[idd[idx[1]]], re);
                re = cal(tmp[idd[idx[2]]-1]-'0', tmp[idd[idx[2]]], re);
            }
        }
        if(re == 24) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    return 0;
}
