#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// 在此处补充你的代码
		friend istream & operator>>(istream &, Point &);
		friend ostream & operator<<(ostream &, Point &);
};
istream & operator>>(istream &o, Point &p){
	o >> p.x >> p.y;
	return o;
}

ostream & operator<<(ostream &o, Point &p){
	o << p.x << ',' << p.y;
	return o;
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}