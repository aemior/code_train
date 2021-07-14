#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
    private:
        int len;
        unsigned char data[210];
    public:
        CHugeInt():len(0){};
        CHugeInt(const char *s) {
            for (len = 0; *(s+len); ++len) {}
            if (len)
                for (int i=len-1; i>=0; --i) {
                    data[len-1-i] = *(s+i) - '0';
                }
        }
        CHugeInt(int n) {
            len = 0;
            do {
                data[len++] = n%10;
            } while (n/=10);
        }
        CHugeInt(const CHugeInt &a) {
            len = a.len;
            for (int i=0; i<len; ++i) {
                data[i] = a.data[i];
            }
        }
       friend ostream & operator<<(ostream &o, const CHugeInt &I) {
            for (int i=I.len-1; i>=0; --i) {
                o << char(I.data[i] + '0');
            }
            return o;
       }
        CHugeInt operator+ (CHugeInt &b) {
            CHugeInt res;
            int minlen = len<b.len?len:b.len;
            int maxlen;
            CHugeInt *l;
            if (len > b.len) {
                l = this;
                maxlen = len;
            } else {
                l = &b;
                maxlen = b.len;
            }
            int ac=0,tc;
            for (; res.len<minlen; ++res.len) {
                tc = ac + data[res.len] + b.data[res.len];
                if (tc >= 10) {
                    ac = 1;
                    tc = tc - 10;
                } else {
                    ac = 0;
                }
                res.data[res.len] = tc; 
            }
            for (;res.len<maxlen; ++res.len) {
                tc = ac + l->data[res.len];
                if (tc >= 10) {
                    ac = 1;
                    tc = tc - 10;
                } else {
                    ac = 0;
                }
                res.data[res.len] = tc; 
            }
            if (ac) res.data[res.len++] = 1;
            return res;
        }
        friend CHugeInt operator + (int n, CHugeInt &a) {
            CHugeInt tmp(n);
            return tmp+a;
        }
        CHugeInt operator + (int n) {
            CHugeInt tmp(n);
            return *this + tmp;
        }
        CHugeInt & operator = (const CHugeInt &a) {
            len = a.len;
            for (int i=0; i<len; ++i) {
                data[i] = a.data[i];
            }
        }
        void operator += (int n) {
            CHugeInt tmp(n);
            *this = *this + tmp;
        }
        CHugeInt & operator ++ (){
            *this += 1;
            return *this;
        }
        CHugeInt operator ++ (int) {
            CHugeInt tmp=*this;
            *this += 1;
            return tmp;
        }


// 在此处补充你的代码
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}