#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    long n, tmp, t1, t2, t3, t4, md;
    cin >> n;
    md = n/2;
    for(int i=0; i<n; i++){
        cin >> tmp;
        if(i==0) t1=tmp;
        if(i==(n-1)) t2=tmp;
        if(i==(md-1)) t3=tmp;
        if(i==(md)) t4=tmp;
    }
    if(t1>t2){
        cout << t1 << ' ';
    }
    else{
        cout << t2 << ' ';
    }
    if((n%2)==0){
        if(((t3+t4)%2) == 0)
            cout << (t3+t4)/2 << ' ';
        else{
            cout << fixed << setprecision(1);
            cout << ((double)(t3+t4))/2 << ' ';
        }

    }
    else{
        cout << t4 << ' ';
    }
    if(t1 < t2){
        cout << t1 << endl;
    }
    else cout << t2 << endl;
    return 0;
}
