#include <iostream>
using namespace std;

struct A
{
	int v;
	A(int vv):v(vv) { }
	const A * getPointer() const {
		return this;
	}
// 在此处补充你的代码
};

int main()
{
	const A a(10);
	const A * p = a.getPointer();
	cout << p->v << endl;
	return 0;
}