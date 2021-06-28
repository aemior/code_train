#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
#include <bits/stdc++.h>
using namespace std;
const int MAX = 110; 
class CHugeInt {
	private:
		unsigned char data[300];
        char str[250];
        int len;
	public:
		CHugeInt(const char* s){
			len = strlen(s);
			for(int i=0; i<len; ++i){
                data[i] = s[len-1-i] - '0';
            }
		}
        CHugeInt(int a){
            int i=0;
            do{
                data[i] = a%10;
                a = a/10;
                ++i;
            }while(a != 0);
            len = i;
        }
        CHugeInt(CHugeInt & a){
            len = a.len;
            memcpy(data, a.data, sizeof(unsigned char)*len);
        }
        CHugeInt operator+(CHugeInt & a){
            CHugeInt tmp(*this);
            int i=0, up, down;
            unsigned char of=0, tc, *high;
            if(a.len < len){
                up = len;
				down = a.len;
				high = data;
            }
            else{
                up = a.len;
				down = len;
				high = a.data;
            }
            for(; i<down; ++i){
                tc = of+a.data[i]+data[i];
                if(tc > 9){
                    tmp.data[i] = tc - 10;
                    of = 1;
                }
                else{
                    tmp.data[i] = tc;
                    of = 0;
                }
            }
			for(; i<up; ++i){
				tc = of + high[i];
				if(tc > 9){
					tmp.data[i] = tc - 10;
					of = 1;
				}
				else{
					tmp.data[i] = tc;
					of = 0;
				}
			}
            if(of){
                tmp.data[i] = of;
                ++i;
            }
            tmp.len = i;
            return tmp;
        }
        CHugeInt operator+(int a){
            CHugeInt tmp(a);
			return *this+tmp;
        }

        operator char* (){
            for(int i=0; i<len; ++i){
                str[len-1-i] = data[i] + '0';
            }
            str[len] = '\0';
            return str;
        }
        void operator+=(int a){
            int i=0;
            unsigned char of=0, tc;
            while(a != 0 || i<len){
                tc = of+(a%10)+data[i];
                if(tc > 9){
                    data[i] = tc - 10;
                    of = 1;
                }
                else{
                    data[i] = tc;
                    of = 0;
                }
                a = a/10;
                ++i;
            }
            if(of){
                data[i] = of;
                ++i;
            }
			if(i > len)
				len = i;
        }
        CHugeInt & operator++(){
            int i=0;
            unsigned char of=1, tc;
            while(of){
                tc = of + data[i];
                if(tc > 9){
                    data[i] = tc - 10;
                    of = 1;
                }
                else{
					data[i] = tc;
                    of = 0;
				}
                ++i;
            }
            if(i>len){
				len = i;
            }
            return *this;
        }
        CHugeInt operator++(int){
            CHugeInt tmp(*this);
            int i=0;
            unsigned char of=1, tc;
            while(of){
                tc = of + data[i];
                if(tc > 9){
                    data[i] = tc - 10;
                    of = 1;
                }
                else{
                    of = 0;
					data[i] = tc;
				}
                ++i;
            }
            if(i>len){
                len = i;
            }
            return tmp;
        }
};

CHugeInt operator+(int a, CHugeInt &b){
    return b+a;
// 在此处补充你的代码
};
int  main() 
{ 
	char s[210];
	int n;
	freopen("test.txt", "r", stdin);
	freopen("res.txt","w",stdout);

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