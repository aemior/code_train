#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("test3.txt", "r", stdin);
    int n, m, p, q,t,s;
    vector<int> pos;
    vector<int> stud;
    cin >> n >> m;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i=0; i<n; i++){
        pos.push_back(i+1);
        stud.push_back(i+1);
    }
    for(int i=0; i<m; i++){
        cin >> p >> q;
        if(q == 0) continue;
        s = stud[p-1]+q;
        if(q<0){
            for(int j=(stud[p-1]-1); j>=s; j--){
                stud[pos[j-1]-1] += 1;
                pos[j] = pos[j-1];
            }
        }
        else{
            for(int j=stud[p-1]+1; j<=s; j++){
                stud[pos[j-1]-1] -= 1;
                pos[j-2] = pos[j-1];
            }
        }
        stud[p-1] = s;
        pos[s-1] = p;
    }
    for(int i=0; i<n; i++){
        cout << pos[i] << ' ';
    }
    cout << endl;
    return 0;
}

/*
struct Node{
    Node* last = NULL;
    Node* next = NULL;
    int num;
};

void print_n(Node *head){
    Node* tp=head;
    cout << "#DEBUG CHAIN>";
    while(true){
        cout << head->num << ' ';
        if(head->next == NULL) break;
        else{
            head = head->next;
        }
    }
    cout << endl;
}

int main()
{
    freopen("test2.txt", "r", stdin);
    int n, m, p, q,t;
    cin >> n >> m;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    Node* aqu = new Node[n];
    for(int i=1; i<(n-1); i++){
        aqu[i].last = &aqu[i-1];
        aqu[i].next = &aqu[i+1];
        aqu[i].num = i+1;
    }
    aqu[0].next = &aqu[1];
    aqu[0].num = 1;
    aqu[n-1].last = &aqu[n-2];
    aqu[n-1].num = n;
    Node* head = &aqu[0];
    Node* cur;
    Node* tpp;
    Node* conter;
    for(int i=0; i<m; i++){
        cin >> p >> q;
        if(q == 0) continue;
        cur = head;
        while(true){
            //cout << "#DEBUG CUR > " << cur->num << endl;
            if(cur->num == p){
                tpp = cur;
                if(cur->last == NULL){
                    head = cur->next;
                    head->last = NULL;
                }
                else if(cur->next == NULL){
                    cur->last->next = NULL;
                }
                else{
                    cur->last->next = cur->next;
                    cur->next->last = cur->last;
                }
                //print_n(head);
                if(q > 0){
                    t = q;
                    for(int j=0; j<t; j++){
                        cur = cur->next;
                    }
                    conter = cur->next;
                    cur->next = tpp;
                    tpp->last = cur;
                    if(conter == NULL){
                        tpp->next = NULL;
                    }
                    else{
                        conter->last = tpp;
                        tpp->next = conter;
                    }
                }
                else{
                    t = -q;
                    for(int j=0; j<t; j++){
                        cur = cur->last;
                    }
                    conter = cur->last;
                    cur->last = tpp;
                    tpp->next = cur;
                    if(conter == NULL){
                        tpp->last == NULL;
                        head = tpp;
                    }
                    else{
                        tpp->last = conter;
                        conter->next = tpp;
                    }

                }
                //print_n(head);
                break;
            }
            cur = cur->next;
        }
    }
    while(true){
        cout << head->num << ' ';
        if(head->next == NULL){
            break;
        }
        else head = head->next;
    }
    cout << endl;
    return 0;
}
*/
