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
    point operator -(const point p){
        point re(x - p.x, y - p.y, 1);
        return re;
    }
    int operator *(const point p){
        int re = (x * p.y) - (y * p.x);
        return re;
    }
    void operator =(const point p){
        x=p.x;
        y=p.y;
        i=p.i;
    }
};

point::point(){};

bool cmpare_point(point A, point B){
    if(A.x == B.x) return (A.y > B.y);
    else return A.x > B.x;
}

class trg{
public:
    point a,b,c;
    trg(point A, point B, point C);
    bool intrg(point T);

};

trg::trg(const point A, const point B, const point C){
    a = A;
    b = B;
    c = C;
}

bool trg::intrg(point T){
    point Ta=a-T,Tb=b-T,Tc=c-T;
    int t1 = Ta*Tb,t2 = Tb*Tc,t3 = Tc*Ta;
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
        int tx,ty;
        vector<point> points_pool;
        vector<trg> all_trg;
        for(int j=0; j<n3; j++){
            cin >> tx >> ty;
            point tmp(tx,ty,j);
            points_pool.push_back(tmp);
        }

        sort(points_pool.begin(), points_pool.end(), cmpare_point);

        while(points_pool.size() != 0){
            int tmp_point = points_pool.size()-1;
            trg tmpt(points_pool[tmp_point], points_pool[tmp_point-1], points_pool[tmp_point-2]);
            all_trg.push_back(tmpt);
            for(tmp_point=0;tmp_point<3;tmp_point++){
                points_pool.pop_back();
            }
        }

        for(int j=0; j<all_trg.size(); j++){
            cout << all_trg[j].a.i+1 << ' ' << all_trg[j].b.i+1 << ' ' << all_trg[j].c.i+1 << endl;
        }
    }
    return 0;
}
