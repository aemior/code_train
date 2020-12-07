#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test2.txt", "r", stdin);
    int n,tmp,rows,st;
    cin >> n;
    vector<bool> seats;
    for(int i=0; i<100; i++) seats.push_back(true);
    for(int i=0; i<n; i++){
        cin >> tmp;
        for(int k=0; k<100; k=k+5){
            rows = 0;
            st = -1;
            for(int p=0; p<5; p++){
                if(seats[k+p]){
                    rows = rows + 1;
                }
                else st = p;
            }
            if(rows >= tmp){
                for(int p=st+1; p<(st+1+tmp); p++){
                    seats[k+p] = false;
                    cout << k+p+1 << ' ';
                }
                cout << endl;
                break;
            }
            else if(k==95){
                for(int p=0; p<100; p++){
                    if(seats[p]){
                        seats[p] = false;
                        tmp = tmp-1;
                        cout << p+1 << ' ';
                        if(tmp == 0){
                            cout << endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
