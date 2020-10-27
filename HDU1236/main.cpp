#include <bits/stdc++.h>

using namespace std;

struct p_node{
    int score;
    string ID;
}AS[1010];

bool compare_p(p_node A, p_node B){
    if(A.score != B.score) return A.score>B.score;
    else{
        return A.ID < B.ID;
    }
}


int main()
{
    freopen("test.txt", "r", stdin);
    int N,M,G;
    while((cin >> N), N){
        cin >> M >> G;
        int t_s, t_n, q_id, p_cnt=0;
        long s_a;
        vector<int> s_l;
        string s_id;
        for(int j=0; j<M; j++){
            cin >> t_s;
            s_l.push_back(t_s);
        }
        for(int j=0; j<N; j++){
            cin >> s_id;
            cin >> t_n;
            s_a = 0;
            for(int k=0; k<t_n; k++){
                cin >> q_id;
                s_a = s_a + s_l[q_id-1];
            }
            if(s_a >= G){
               AS[p_cnt].score = s_a;
               AS[p_cnt].ID = s_id;
               p_cnt++;
            }
        }
        sort(AS,AS+p_cnt, compare_p);
        cout << p_cnt << endl;
        for(int i=0; i<p_cnt; i++){
            cout << AS[i].ID << ' ' << AS[i].score << endl;
        }
    }
    return 0;
}
