#include <iostream>

using namespace std;

class CDemo{
    int v;
    public:
    	CDemo(int i=0):v(i) {}
    	CDemo(const CDemo & i):v(i.v) {}
    	CDemo operator++(int);
    	CDemo & operator++();
	operator int(){return v;}
	friend CDemo & operator--(CDemo &);
	friend CDemo operator--(CDemo &, int);
};

CDemo CDemo::operator++(int){
    CDemo tmp(*this);
    v++;
    return tmp;
}
CDemo & CDemo::operator++(){
    v++;
    return *this;
}
CDemo operator--(CDemo & a, int){
    CDemo tmp(a);
    a.v--;
    return tmp;
}
CDemo & operator--(CDemo & a){
    a.v--;
    return a;
}

int main(){
    CDemo d(5);
    cout << (d++) << ',';
    cout << d << ',';
    cout << (++d) << ',';
    cout << d << endl;
    cout << (d--) << ',';
    cout << d << ',';
    cout << (--d) << ',';
    cout << d << endl;
    return 0;
}
