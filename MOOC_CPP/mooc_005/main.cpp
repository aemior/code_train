#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
	private:
		char name[30];
		int age,ID; 
		int score[4];
	public:
		void input(){
			char t = cin.peek();
			int tmp = 0;
			char *ns = name;
			while (t != ',')
			{
				cin >> *ns; 
				++ns;
				t = cin.peek();
			}
			cin.get();
			t = cin.peek();
			while (t != ',')
			{
				tmp = tmp*10 + (cin.get() - '0');
				t = cin.peek();
			}
			ID = tmp;
			cin.get();
			t = cin.peek();
			for (int i=0; i<4; ++i) {
				tmp = 0;
				while (t != ',')
				{
					tmp = tmp*10 + (cin.get() - '0');
					t = cin.peek();
				}
				score[i] = tmp;
				cin.get();
				cin.peek();
			}
		}
// 在此处补充你的代码
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}