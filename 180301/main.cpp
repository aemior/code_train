#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int tmp=1,cnt=0, adc=0;
    while(true){
        cin >> tmp;
        if(tmp == 2){
                adc = adc+2;
                cnt = cnt + adc;
        }
        else if(tmp == 1){
            adc = 0;
            cnt = cnt+1;
        }
        else{
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}
