#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x,y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int main()
{
    int N,x,y;
    double tx=0,ty=0;
    vector<int> X;
    vector<int> Y:
    cout >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        tx+=x;
        ty+=y;
        X.push_back(x);
        Y.push_back(y);
    }
    tx = tx/N;
    ty = ty/N;
    int bx,by;
    if(tx-(int)tx > 0.5) bx = (int)tx + 1;
    else bx = (int)tx;
    if(ty-(int)ty > 0.5) by = (int)ty + 1;
    else by = (int)ty;
    int b_l=0,b_u=N-1, b_m = (bl+b_u)/2;
    for(int i=0; i<N; i++){
        if(b_u - b_l == 1){
            by = Y[b_l];
        }
    }
    return 0;
}
