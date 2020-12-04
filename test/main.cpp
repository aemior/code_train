#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 1234790324;
    vector<int> stk;
    while(n>0){
        cout << ' ' << n%10;
        stk.push_back(n%10);
        n=n/10;
    }
    string ttstr;
    char buf[100];
    cout << endl;
    for(vector<int>::iterator it=stk.begin(); it != stk.end(); it++){
        cout << *it << ' ';
        sprintf(buf,"%d", *it);
        string tpstr(buf);
        ttstr = ttstr + tpstr;
    }
    cout << endl;
    cout << ttstr << endl;
    long long o;
    int a,b;
    float c;
    sscanf(ttstr.c_str(), "%Ld", &o);
    sscanf("12 34 56.69","%d%d%f", &a,&b,&c);
    cout << "Hello world! " << o << endl;
    cout << a << ' ' << b << ' ' << c << endl;
    printf("%.2f", c);
    return 0;
}
