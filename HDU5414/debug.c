#include <iostream>

using namespace std;
contst int N = 100005;
char s[N], t[N];

int main(){
    int T, i, j;
    freopen("test.txt", "r", stdin);
    bool same;
    scanf("%d", T);
    while(T--){
        scanf("%s%s", &s, &t);
        same = true;
        for(i=j=0; t[i] != '\0'; i++){
            if(same && t[i] == t[0] && s[i] != t[0]){
                break;
            }
            if(t[i] != t[0]){
                same = false;
            }
            if(s[j] != '\0' && t[i] == s[j]){
                j++;
            }
        }
        if(s[j] == '\0' && t[i] == '\0'){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
