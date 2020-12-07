#include <bits/stdc++.h>

using namespace std;

bool mycmp(int i, int j);

class CTestCmp {
public:
        bool operator() (int i, int j) {
                //return !!(lc.num < rc.num);
                return i>j;
        }
};


int main()
{
    int a[] = {1,5,7,8,2,2,6};
    vector<int> v(a, a+7);
    for(int i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    sort(v.begin(), v.end(), mycmp);
    set<int, CTestCmp> s;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
        s.insert(v[i]);
    }
    cout << endl << "+++++++++++++"<< endl;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}

bool mycmp(int i, int j){
    return i>j;
}
