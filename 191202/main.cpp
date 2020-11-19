#include <bits/stdc++.h>

using namespace std;

class coodic{
public:
    void add(int x, int y);
    bool f(int x, int y);
    void cnt(vector<int> &c_get);
private:
    int tx,ty;
    map<string, vector<int> > sc;
};

void coodic::add(int x, int y){
    stringstream ss;
    ss << x << '_' << y;
    string tmp = ss.str();
    vector<int> txy;
    txy.push_back(x);
    txy.push_back(y);
    sc[tmp] = txy;

}

bool coodic::f(int x, int y){
    stringstream ss;
    ss << x << '_' << y;
    string tmp = ss.str();
    map<string, vector<int> >::iterator ifid = sc.find(tmp);
    if(ifid != sc.end()) return true;
    else return false;
}

void coodic::cnt(vector<int> &c_get){
    int tcnt;
    map<string, vector<int> >::iterator iter = sc.begin();
    for(;iter != sc.end(); iter++){
        tcnt = 0;
        vector<int> tiv = iter->second;
        if(f(tiv[0]+1, tiv[1]) &&
           f(tiv[0]-1, tiv[1]) &&
           f(tiv[0], tiv[1]+1) &&
           f(tiv[0], tiv[1]-1)){
               if(f(tiv[0]-1,tiv[1]-1)) tcnt += 1;
               if(f(tiv[0]-1,tiv[1]+1)) tcnt += 1;
               if(f(tiv[0]+1,tiv[1]-1)) tcnt += 1;
               if(f(tiv[0]+1,tiv[1]+1)) tcnt += 1;
               c_get[tcnt] += 1;
           }
    }
}

int main()
{
    freopen("test2.txt", "r", stdin);
    int n,tx,ty;
    vector<int> cnt;
    for(int i=0; i<5; i++)
        cnt.push_back(0);
    coodic dic;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tx >> ty;
        dic.add(tx, ty);
    }
    dic.cnt(cnt);
    for(int i=0; i<5; i++){
        cout << cnt[i] << endl;
    }
    return 0;
}
