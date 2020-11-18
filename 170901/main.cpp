#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, rb,tmp, g5, g3, tt=0;
    cin >> N;
    rb = N/10;
    g5 = rb/5;
    tt = 7*g5;
    tmp = rb%5;
    g3 = tmp/3;
    tt += 4*g3;
    cout << tt+(tmp%3) << endl;
    return 0;
}
