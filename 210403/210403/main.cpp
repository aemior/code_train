#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void set_exp_time(int);

int N, T_def, T_max, T_min, n, t_i, IP, ET;
string H;
string Src;
string Dst;
string Typ;

map<int, string> IP_POOL;
int *IP_STA;
int *IP_EXP;

vector<int> IPS(string key) {
    vector<int> res;
    auto iter = IP_POOL.begin();
    while(iter != IP_POOL.end()) {
        if (iter->second == key) {
            res.push_back(iter->first);
        }
        iter++;
    }
    return res;
}

int find_min_FP_IP() {
    for (int i=0; i<N; ++i) {
        if (IP_STA[i] == 0) return i+1;
    }
    return 0;
}
int find_min_FP_ET() {
    for (int i=0; i<N; ++i) {
        if (IP_STA[i] == 3) return i+1;
    }
    return 0;
}

void set_EXP_STA() {
    for (int i=0; i<N; ++i) {
        if (IP_EXP[i] <= t_i && IP_STA[i] == 2)
            IP_STA[i] = 3;
        if (IP_EXP[i] <= t_i && IP_STA[i] == 1)
            IP_STA[i] = 0;
    }
}

void REQ() {
    if (Dst != H) {
        // 1#
        vector<int> ips = IPS(Src);
        for (auto it=ips.begin(); it!=ips.end(); ++it) {
            if (IP_STA[*it-1] == 1) {
                IP_STA[*it-1] = 0;
                IP_EXP[*it-1] = 0;
                IP_POOL.erase(*it);
            }
        }
        return;
    }
    // 2#
    auto it_test = IP_POOL.find(IP);
    if (IP > N || IP <= 0 || it_test == IP_POOL.end() || IP_POOL[IP] != Src) {
        cout << H << ' ' << Src << ' ' << "NAK" << ' ' << IP << ' ' << 0 << endl;
        return;
    }
    // 3#
    IP_STA[IP-1] = 2;
    // 4#
    set_exp_time(IP);
    // 5#
    cout << H << ' ' << Src << " ACK" << ' ' << IP << ' ' << IP_EXP[IP-1] << endl;
    return;
}

void set_exp_time(int re_IP) {
    if (ET == 0) IP_EXP[re_IP-1] = t_i + T_def;
    else if (ET-t_i <= T_max) {
        if (ET-t_i >= T_min) {
            IP_EXP[re_IP-1] = ET;
        } else {
            IP_EXP[re_IP-1] = t_i + T_min;
        }
    } else {
        IP_EXP[re_IP-1] = t_i + T_max;
    }
}

int main()
{
    freopen("test_2.txt", "r", stdin);
    cin >> N >> T_def >> T_max >> T_min;
    cin >> H;
    cin >> n;
    IP_STA = new int[N];
    IP_EXP = new int[N];
    memset(IP_STA, 0, sizeof(int)*N);
    memset(IP_EXP, 0, sizeof(int)*N);
    while(n--) {
        cin >> t_i >> Src >> Dst >> Typ >> IP >> ET;
        //cout << t_i << endl;
        set_EXP_STA();
        if (Dst == H) {
            if (!(Typ == "DIS")) {
                if (Typ == "REQ") {
                    REQ();
                }
            }
        } else if (Dst == "*") {
            if (Typ == "DIS") {
                int re_IP=0, re_FP_IP=0, re_FP_ET=0;
                vector<int> tmp_ips = IPS(Src);
                if (tmp_ips.size() != 0) {
                    re_IP = tmp_ips[0]; // 1.1
                } else {

                    re_FP_IP = find_min_FP_IP();
                    re_FP_ET = find_min_FP_ET();
                    if (re_FP_IP) re_IP = re_FP_IP;
                    else re_IP = re_FP_ET;
                    /*
                    if (re_FP_ET && re_FP_IP) {
                        if (re_FP_ET < re_FP_IP && IP_EXP[re_FP_ET-1] != t_i) re_IP = re_FP_ET;
                        else re_IP = re_FP_IP;
                    } else if (re_FP_IP) re_IP = re_FP_IP;
                    else if (re_FP_ET) re_IP = re_FP_ET;*/
                }
                if (re_IP) { //1.4
                    // 2#
                    IP_STA[re_IP-1] = 1;
                    IP_POOL[re_IP] = Src;
                    // 3#
                    set_exp_time(re_IP);
                    // 4#
                    cout << H << ' ' << Src << ' ' << "OFR" << ' ' << re_IP << ' ' << IP_EXP[re_IP-1] << endl;
                }
            }
        } else if (Typ == "REQ") {
            REQ();
        }
        //cout << t_i << ' ' <<  Src << '>' << Dst << endl;
    }
    return 0;
}
