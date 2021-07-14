#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
        friend istream & operator>>(istream &o, Point &p) {
            o >> p.x;
            o >> p.y;
            return o;
        }
        friend ostream & operator<<(ostream &o, Point &p) {
            o << p.x << ',' << p.y;
            return o;
        }
// 在此处补充你的代码
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}