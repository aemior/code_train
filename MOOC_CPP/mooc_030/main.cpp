#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
	private:
		bool isEND;
	public:
		MyCin & operator>>(int &n) {
			if (isEND) {
				cin >> n;
				isEND = (n != -1);
			}
			return *this;
		}
		operator bool() {
			return isEND;
		}
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}