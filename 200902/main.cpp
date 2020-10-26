#include <iostream>
#include <cstdio>
#include <vector>

class region{
public:
    region(int g_xl, int g_yd, int g_xr, int g_yu);
    bool is_in(int g_x, int g_y);
private:
    int  xl,yd,xr,yu;
};

region::region(int g_xl, int g_yd, int g_xr, int g_yu){
    xl = g_xl;
    yd = g_yd;
    xr = g_xr;
    yu = g_yu;
}

bool region::is_in(int g_x, int g_y){
    if(g_x >= xl && g_x <=xr && g_y >= yd && g_y <= yu)
        return true;
    return false;
}


int main()
{
    freopen("test2.txt", "r", stdin);
    int  n,k,t,xl,yd,xr,yu;
    std::cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    region r(xl, yd, xr, yu);
    int stay_number = 0, pass_number = 0;
    for(int i=0; i<n; i++){
        int count = 0;
        bool pass_flg = false, stay_flg = false;
        for(int j=0; j<t; j++){
            int tmp_x,tmp_y;
            std::cin >> tmp_x >> tmp_y;
            if(!stay_flg){
            if(r.is_in(tmp_x, tmp_y)){
                count++;
                pass_flg = true;
            }
            else{
                count = 0;
            }
            if(count >= k){
                stay_number++;
                stay_flg = true;
            }
            }
        }
        if(pass_flg){
            pass_number++;
        }
    }
    std::cout << pass_number << std::endl;
    std::cout << stay_number << std::endl;
    return 0;
}
