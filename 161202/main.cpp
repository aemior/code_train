#include <iostream>

using namespace std;

int main()
{
    int T,tmp;
    cin >> T;
    if(T<= 3500){
        cout << T << endl;
        return 0;
    }
    else if(T <= 4955){
        tmp = (T-3500)/97*100;
        cout << 3500+tmp << endl;
    }
    else if(T <= 7655){
        tmp = (T-4955)/90*100;
        cout << 3500+1500+tmp << endl;
    }
    else if(T <= 11255){
        tmp = (T-7655)/80*100;
        cout << 3500+4500+tmp << endl;
    }
    else if(T <= 30755){
        tmp = (T-11255)/75*100;
        cout << 3500+9000+tmp << endl;
    }
    else if(T <= 44755){
        tmp = (T-30755)/70*100;
        cout << 3500+35000+tmp << endl;
    }
    else if(T <= 61005){
        tmp = (T-44755)/65*100;
        cout << 3500+55000+tmp << endl;
    }
    else{
        tmp = (T-61005)/55*100;
        cout << 3500+80000+tmp << endl;
    }
    return 0;
}
