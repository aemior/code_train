#include <bits/stdc++.h>

using namespace std;

class C;
class B;
class A;

class A{
	private:
		int val;
	public:
		A(int v):val(v){}
		C attack(B *b);
		friend ostream & operator<<(ostream &o, A &a){
			o << a.val;
			return o;
		}
		~A(){
			cout << "A decons with val:" << val << endl;
		}
};

class B{
	public:
		friend class C;
		void add(A* a){pool.push_back(a);}
		void use(int idx);
		void Print(){
			for (auto it=pool.begin(); it!=pool.end(); ++it){
				cout << **it << ' ';
			}
			cout << endl;
		}
		~B(){
			for (auto it=pool.begin(); it!=pool.end(); ++it) {
				delete *it;
			}
		}
	private:
		vector<A*> pool;

};

class C{
	private:
		B* bb;
		A* aa;
	public:
		C(B* b, A*a):bb(b), aa(a){}
		void operator()(){
			for (auto it = bb->pool.begin(); it != bb->pool.end(); ++it) {
				if ((*it) == aa) {
					bb->pool.erase(it);
					delete aa;
					return;
				}
			}
		}
};

C A::attack(B *b){
	return C(b, this);
}

void B::use(int idx){
	(pool[idx]->attack(this))();
}


int main () {
	B test;
	for (int i=0; i<10; ++i) {
		test.add(new A(i));
	}
	test.Print();
	test.use(4);
	test.Print();
	test.use(7);
	test.Print();
	return 0;
}