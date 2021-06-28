#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
    private:
        int ** data;
        int X,Y;
    public:
        Array2(){data = NULL;};
        Array2(int y, int x){
            X = x;
            Y = y;
            data = new int*[y];
            for(int i=0; i<y; ++i){
                data[i] = new int[x];
            }
        }
        int * & operator[](int i){
            return data[i];
        }
        int & operator()(int i, int j){
            return data[i][j];
        }
        Array2 & operator=(Array2 &a){
            X = a.X;
            Y = a.Y;
            if(data){
                for(int i=0; i<Y; i++){
                    delete [] data[i];
                }
                delete [] data;
            }
            data = new int*[a.Y];
            for(int i=0; i<a.Y; ++i){
                data[i] = new int[a.X];
                memcpy(data[i], a.data[i], sizeof(int)*a.X);
            }
            return *this;
        }
        ~Array2(){
            if(data){
                for(int i=0; i<Y; ++i){
                    delete [] data[i];
                }
                delete [] data;
            }
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