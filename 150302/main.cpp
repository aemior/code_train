#include <bits/stdc++.h>

using namespace std;



int main()
{
    freopen("test.txt", "r", stdin);
    int n,tmp;
    map<int, int> nums;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> tmp;
        map<int, int>::iterator it = nums.find(tmp);
        if(it == nums.end()){
            nums[tmp] = 1;
        }
        else{
            nums[tmp] = nums[tmp] + 1;
        }
    }
    set<int> n_t;
    for(map<int, int>::iterator it=nums.begin(); it != nums.end(); it++){
        n_t.insert(it->second);
    }
    for(set<int>::reverse_iterator it=n_t.rbegin(); it != n_t.rend(); it++){
        for(map<int, int>::iterator it2=nums.begin(); it2!=nums.end(); it2++){
            if(it2->second == *it){
                cout << it2->first << ' ' << it2->second << endl;
            }
        }
    }
    return 0;
}
