#include <iostream>

using namespace std;

class A{
	int ID;
	public:
		A(){}
		A(int idx):ID(idx) {
			cout << "A Const ID:" << idx << endl;
		}
		A(A &a) {
			cout << "A Copy ID:" << a.ID << endl;
		}
		A(const A &a) {
			cout << "A const Copy ID:" << a.ID << endl;
		}
};

A & func_1(int x, int y) {
	A tmp(x+y);
	return tmp;
}

A func_2(int x, int y) {
	A tmp(x+y);
	return tmp;
}
A func_3(int x, int y) {
	return A(x+y);
}

int main () {
	//A I = func_1(1,2);
	auto J = func_2(3,4);
	auto k = func_3(5,6);
	A r = func_3(5,6);
	return 0;
}