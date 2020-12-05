#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *next=NULL;
    int num;
};

bool del_node(Node* last, Node* current){
    if(current->next == last) return true;
    else{
        last->next = current->next;
        return false;
    }
}

bool is_k(int n_get, int & k){
    if((n_get%10 == k) || (n_get%k == 0)) return true;
    else return false;
}

int main()
{
    int n,k,N=1;
    cin >> n >> k;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    Node *guys = new Node[n];
    for(int i=0; i<(n-1); i++){
        guys[i].next = &guys[i+1];
        guys[i].num = i+1;
    }
    guys[n-1].next = &guys[0];
    guys[n-1].num = n;
    Node* l=&guys[n-1];
    Node* c=&guys[0];
    while(true){
        if(is_k(N, k)){
            //cout << N <<" #LAST >" << l->num << " CURRENT>" << c->num << " NEXT>" << c->next->num << endl;
            if(del_node(l, c))
            {
                break;
            }
            c=c->next;
        }
        else{
            l=c;
            c=c->next;
        }
        N=N+1;
    }
    cout << l->num << endl;
    return 0;
}
