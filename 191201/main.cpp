#include <bits/stdc++.h>

using namespace std;

bool check_s(int i){
    int s=1;
    while(s<i){
        if((i%(s*10))/s == 7) return true;
        s = s*10;
    }
    if(i/s == 7) return true;
    return false;
}

int main()
{
    int n,cnt=0,i=0,lp=0;
    vector<int> da;

    for(int i=0; i<4; i++){
        da.push_back(0);
    }
    cin >> n;

    while(true){
        i++;
        bool tmp = check_s(i);
        //cout << i << ' ' << (i%7==0) << ' ' << tmp << ' ' << lp <<" <DEBUG" << endl;
        if(i%7==0 || tmp){
            da[lp] = da[lp] + 1;
        }
        else{
            cnt++;
            if(cnt == n) break;
        }
        lp++;
        if(lp == 4) lp=0;
    }
    for(int i=0; i<4; i++){
        cout << da[i] << endl;
    }
    return 0;
}
