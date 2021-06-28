#include <iostream>
#include <string.h>

using namespace std;

class CArray{
    private:
        int * ptr;
        int size;
    public:
        CArray();
        CArray(CArray &);
        ~CArray();
        void push_back(int);
        int length();
        int & operator[](int);
        CArray & operator=(CArray);
};

CArray::CArray(){
    size = 0;
    ptr = NULL;
}
CArray::CArray(CArray & a){
    ptr = NULL;
    size = a.size;
    if(a.size){
        ptr = new int[size];
        memcpy(ptr, a.ptr, sizeof(int)*size);
    }
}

CArray::~CArray(){
    if(size){
        delete []ptr;
    }
}

void CArray::push_back(int i){
    if(size){
        int * tmp = new int[size+1];
        memcpy(tmp, ptr, sizeof(int)*size);
        delete []ptr;
        ptr = tmp;
        ptr[size] = i;
    }
    else{
        ptr = new int[1];
        ptr[0] = i;
    }
    ++size;
}

int CArray::length(){
    return size;
}

int & CArray::operator[](int i){
    return ptr[i];
}

CArray & CArray::operator=(CArray a){
    if(size){
        delete []ptr;
        ptr = NULL;
    }
    size = a.size;
    if(a.size){
        ptr = new int[size];
        memcpy(ptr, a.ptr, sizeof(int)*a.size);
    }
    return *this;
}

int main(){
    CArray a; // 开始时数组是空的
    for(int i=0; i<5; ++i){
        a.push_back(i); // --> 动态分配内存
    }
    for(int i=0; i<a.length(); ++i){
        cout << a[i] << ' '; // -->重载[]
    }
    cout << endl;
    CArray a2, a3;
    a2 = a; // --> 重载=
    for(int i=0; i<a.length(); ++i){
        cout << a2[i] << ' '; // -->重载[]
    }
    a2 = a3; // a2是空的
    for(int i=0; i<a2.length(); ++i){ // a2.length()返回0
        cout << a2[i] << ' ';
    }
    cout << endl;
    a[3] = 100;
    CArray a4(a); // --> 自定义复制构造函数
    for(int i=0; i<a4.length(); ++i){
        cout << a4[i] << ' ';
    }
    return 0;
}