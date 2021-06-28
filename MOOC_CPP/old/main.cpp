#include <bits/stdc++.h>

using namespace std;

bool mycmp(int i, int j);

class CTestCmp {
public:
        bool operator() (int i, int j) {
                //return !!(lc.num < rc.num);
                return i>j;
        }
};

void swap(int* &a, int* &b){
	int *tmp = a;
	a=b;
	b=tmp;
}

int &
getElement(int *a, int i){
	return a[i];
}

class B{
	public:
		B(){ cout << "B constructor called" << endl;}
		B(B &b){cout << "B Copy constructor called" << endl;}
		B& operator = (const B&){ cout << "B opeartor = called" << endl;}
};

class A{
	public:
		int v;
		B b;
		A(){
			cout << "Constructor called" << endl;
		}
		A(A &a){
			v = a.v;
			cout << "Copy constructor called" << endl;
		}
		A(const A &a){
			v = a.v;
			cout << "Copy constructor called(const)" << endl;
		}
		A(int a){
			v = a;
			cout << "Trans constructor called" << endl;
		}
		~A(){
			cout << "Delete constructor called" << endl;
		}
};


A func(){A tmp(88); return tmp;}
void fund(A tmp){}


int main()
{
	/*
	int a=3,b=5;
	int * pa = & a;
	int * pb = & b;
	swap(pa,pb);
	cout << *pa << "," << *pb << endl;
	int c[] = {1,2,3};
	getElement(c,1) = 10;
	cout << c[1] << endl;

	int * a[] = {
		NULL, new int, new int, new int[6]
	};

	*a[2] = 123;
	a[3][5] = 456;
	if(! a[0] ) {
		cout << * a[2] << "," << a[3][5] << endl;
	}
	cout << "++++++++++"<< endl;
	*/
	cout << "A X,Y" << endl;
	A x, y;
	cout << "=========="  << endl;
	cout << "x.y=5" << endl;
	x.v = 5;
	cout << "==========" << endl;
	cout << "y=6" << endl;
	y = 6;
	cout << "X:" << x.v << endl;
	cout << "Y:" << y.v << endl;
	cout << "=========="  << endl;
	cout << "y=x"  << endl;
	y = x;
	cout << "X:" << x.v << endl;
	cout << "Y:" << y.v << endl;
	cout << "==========" << endl;
	cout << "Change Y" << endl;
	y.v = 8;
	cout << "X:" << x.v << endl;
	cout << "Y:" << y.v << endl;
	cout << "=========="  << endl;
	cout << "y=func" << endl;
	A magic;
	magic = func();
	cout << "magic:" << magic.v << endl;
	cout << "=========="  << endl;
	fund(x);
	cout << "==========" << endl;

	/*
    int a[] = {1,5,7,8,2,2,6};
    vector<int> v(a, a+7);
    for(int i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    sort(v.begin(), v.end(), mycmp);
    set<int, CTestCmp> s;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
        s.insert(v[i]);
    }
    cout << endl << "+++++++++++++"<< endl;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;
    */
    return 0;
}

bool mycmp(int i, int j){
    return i>j;
}
