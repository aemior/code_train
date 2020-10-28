#include <bits/stdc++.h>

using namespace std;

class point{
public:
    int x,y,i;

    point();
    point(int m, int n, int o){
        x=m;
        y=n;
        i=o;
    }
    point operator -(point p){
        point re(x - p.x, y - p.y, 1);
        return re;
    }
    int operator *(point p){
        int re = (x * p.y) - (y * p.x);
        return re;
    }
    void operator =
};

class trg{
public:
    trg(point A, point B, point C);
    bool intrg(point T);
    point* a;
    point* b;
    point* c;
};

trg::trg(point A, point B, point C){
    a = &A;
    b = &B;
    c = &C;
}

bool trg::intrg(point T){
    point Ta,Tb,Tc;
    Ta = a-T;
    Tb = b-T;
    Tc = c-T;
    //point Ta=a-T, Tb=b-T, Tc=c-T;
    int t1 = Ta*Tb;
    int t2 = Tb*Tc;
    int t3 = Tc*Ta;
    if((t1*t2 > 0) && (t2*t3 > 0)){
        return true;
    }
    else return false;
}

int main()
{
    freopen("test.txt", "r", stdin);
    int T,n,n3;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> n;
        n3 = n*3;
        int j=0,tx,ty;
        vector<point> points_pool;
        vector<trg> all_trg;
        for(; j<3; j++){
            cin >> tx >> ty;
            point tmp(tx,ty,j);
            points_pool.push_back(tmp);
        }
        trg tmpt(points_pool[0], points_pool[1], points_pool[2]);
        for(int k=0; k<3; k++) points_pool.pop_back();
        all_trg.push_back(tmpt);
        for(;j<n3;j++){
            cin >> tx >> ty;
            point tmp(tx, ty, j);
            for(int k=0; k<all_trg.size(); k++){
                if(all_trg[k].intrg(tmp)){
                    points_pool.push_back(all_trg[k].c);
                    trg new_trg(all_trg[k].a, all_trg[k].b, tmp);
                    vector<trg>::iterator iter = all_trg.begin()+k;
                    all_trg.erase(iter);
                    all_trg.push_back(new_trg);
                    break;
                }
            }
            points_pool.push_back(tmp);
            if(points_pool.size() == 3){
                trg tmpt(points_pool[0], points_pool[1], points_pool[2]);
                for(int k=0; k<3; k++) points_pool.pop_back();
                all_trg.push_back(tmpt);
            }
        }
        for(int j=0; j<all_trg.size(); j++){
            cout << all_trg[j].a.i << ' ' << all_trg[j].b.i << ' ' << all_trg[j].c.i << endl;
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
