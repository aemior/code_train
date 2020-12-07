#include <bits/stdc++.h>

using namespace std;

void getCursor(int* x, int* y) {
   printf("\033[6n");  /* This escape sequence !writes! the current
                          coordinates to the terminal.
                          We then have to read it from there, see [4,5].
                          Needs <termios.h>,<unistd.h> and some others */
   scanf("\033[%d;%dR", x, y);
}

int main()
{
    int y,d,i,j;
    int nmy[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int smy[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int *lmy;
    bool sflg = false;
    cin >> y >> d;
    if((y%4) == 0 && (y%100) != 0 ) sflg = true;
    else if((y%400) == 0) sflg = true;

    if(sflg) lmy = smy;
    else lmy = nmy;
    for(i=0; i<12; i++){
        for(j=0; j<*(lmy+i); j++){
            d--;
            if(d == 0) break;
        }
        if(d == 0) break;
    }
    cout << i+1 << endl << j+1 << endl;
    return 0;
}
