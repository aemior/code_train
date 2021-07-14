#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
    int r;
    int c;
    int *data;
public:
    Array2(){}
    Array2(int row, int col):r(row), c(col) {
        data = new int[row*col];
    }
    int * operator [] (int row) {
        return data+row*c;
    }
    int & operator () (int row, int col) {
        return *(data+(row*c+col));
    }
    void operator = (Array2 &a) {
        if (r+c) delete []data;
        r = a.r;
        c = a.c;
        data = new int[r*c];
        memcpy(data, a.data, sizeof(int)*r*c);
    }

};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}