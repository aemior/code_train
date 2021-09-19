#include <bits/stdc++.h>

using namespace std;

int N, T_def, T_max, T_min, t_i, n;
string H;
string Src, Dst, Typ;
int IP, ET;

struct IP_INFO{
    int IP;
    int STA;
    int ET;
    string OWN;
    IP_INFO(){
        STA = 0;
        ET = 0;
        OWN = "";
    }
};

IP_INFO* IP_POOL;

int find_by_OWN(){
    for (int i=0; i<N; i++) {
        if (IP_POOL[i].OWN == Src) return IP_POOL[i].IP;
    }
    return 0;
}

int find_by_STA(int sta) {
    for (int i=0; i<N; ++i) {
        if (IP_POOL[i].STA == sta) return IP_POOL[i].IP;
    }
    return 0;
}

void set_ET(int ip) {
    if (ET == 0) IP_POOL[ip-1].ET = t_i + T_def;
    else {
        int t_det = ET - t_i;
        t_det = min(T_max, t_det), t_det = max(T_min, t_det);
        IP_POOL[ip-1].ET = t_i + t_det;
    }
}

void REQ() {
    if (Dst != H) {
        if (int tmp_IP = find_by_OWN()) {
            if (IP_POOL[tmp_IP-1].STA == 1) {
                IP_POOL[tmp_IP-1].STA = 0;
                IP_POOL[tmp_IP-1].OWN = "";
                IP_POOL[tmp_IP-1].ET = 0;
            }
        }
        return;
    }
    if (IP <= N &&  IP > 0 && IP_POOL[IP-1].OWN == Src) {
        IP_POOL[IP-1].STA = 2;
        set_ET(IP);
        cout << H << ' ' << Src << " ACK " << IP << ' ' << IP_POOL[IP-1].ET << endl;
    } else {
        cout << H << ' ' << Src << " NAK " << IP << ' ' << 0 << endl;
    }
}

void D_timer() {
    for (int i=0; i<N; ++i) {
        if (IP_POOL[i].ET <= t_i) {
            if (IP_POOL[i].STA == 2) IP_POOL[i].STA = 3;
            else if (IP_POOL[i].STA == 1) IP_POOL[i].STA = 0;
        }
    }
    return;
}

int main () {
    //freopen("test_2.txt", "r", stdin);
    cin >> N >> T_def >> T_max >> T_min >> H;
    cin >> n;
    IP_POOL = new IP_INFO[N];
    for (int i=0; i<N; ++i) {
        IP_POOL[i].IP = i+1;
    }
    while(n--) {
        cin >> t_i >> Src >> Dst >> Typ >> IP >> ET;
        D_timer();
        if (Dst == "*") {
            if (Typ == "DIS") {
                int re_IP = find_by_OWN();
                if (!re_IP) re_IP = find_by_STA(0);
                if (!re_IP) re_IP = find_by_STA(3);
                if (!re_IP) continue;
                IP_POOL[re_IP-1].STA = 1;
                IP_POOL[re_IP-1].OWN = Src;
                set_ET(re_IP);
                cout << H << ' ' << Src << " OFR " << re_IP << ' ' << IP_POOL[re_IP-1].ET << endl;
            }
        } else if (Dst == H) {
            if (Typ == "REQ") {
                REQ();
            }
        } else if (Typ == "REQ") {
            REQ();
        }
    }
    return 0;
}

