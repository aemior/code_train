#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int n,tmp, x1,y1,x2,y2;
    bool pics[100][100];
    cin >> n;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            pics[i][j] = false;
        }
    }
    for(int i=0; i<n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int a=x1; a<x2; a++){
            for(int b=y1; b<y2; b++){
                pics[a][b] = true;
            }
        }
    }
    int area = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(pics[i][j]) area = area+1;
        }
    }
    cout << area << endl;
    return 0;
}
