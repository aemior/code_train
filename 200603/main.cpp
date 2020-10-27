#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    string tmp;
    bool seg_flg, li_flg;
    int line_count=0, w_count, w;
    cin >> w;
    while(!cin.eof()){
        getline(cin, tmp);

        if(tmp.size() == 0){
            seg_flg = true;
            li_flg = false;
        }
        else if(tmp.size() == 1){
            if(tmp == " "){
                seg_flg = true;
                li_flg = false;
            }
            else{
                if(seg_flg){
                    line_count++;
                    w_count = 1;
                }
                else{
                    if(++w_count > w){
                        if(li_flg){
                            w_count = 3;
                            line_count++;
                        }
                        else{
                            w_count = 1;
                            line_count++;
                        }
                    }
                }
            }
        }
        else{
            if(tmp.substr(0,2) == " *"){
                if(li_flg){
                    line_count++;
                    w_cout = 0;
                }

            }
        }
        for(int i=0; i<tmp.size(); i++){

        }

    }

    return 0;
}
