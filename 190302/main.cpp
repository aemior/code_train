#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,tn;
    cin >> N;
    for(int i=0; i<N; i++){
        char *tmp[10];
        vector<int> nums;
        cin >> tmp;
        for(int j=0; j<7; j+=2){
            tn = atoi(tmp[j]);
            nums.push_back(tn);
        }

    }
    cout << "Hello world!" << endl;
    return 0;
}
