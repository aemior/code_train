#include <iostream>
using namespace std;
class A {
public:
	int val;

	A(int v):val(v){};
    A():val(123){};
    A & GetObj() {
        return *this;
    }
    void operator= (int &v){
        val = v;
    };
// 在此处补充你的代码
};
int main()
{
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}