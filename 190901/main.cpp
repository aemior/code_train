#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test2.txt", "r", stdin);
    int M,N, tmp1, tmp2, tmp3, T=0, k=1, P=0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> tmp1;
        tmp3 = 0;
        for(int j=0; j<M; j++){
            cin >> tmp2;
            tmp1 = tmp1 + tmp2;
            tmp3 = tmp3 - tmp2;
        }
        T = T + tmp1;
        if(tmp3 > P){
            k=i+1;
            P=tmp3;
        }
    }
    cout << T << ' ' << k << ' ' << P << endl;
    return 0;
}
