#include <iostream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
    MyString & operator=(const MyString & a){
    if(p){
        delete []p;
        p = NULL;
    }
	if(a.p){
        p = new char[strlen(a.p) + 1];
        strcpy(p, a.p);
    }
    return *this;
}

MyString & operator=(const char * a){
    if(p){
        delete []p;
        p = NULL;
    }
	if(a){
        p = new char[strlen(a) + 1];
        strcpy(p, a);
    }
    return *this;
}

MyString(MyString & a){
    if(a.p){
        p = new char[strlen(a.p) + 1];
        strcpy(p, a.p);
    }
    else
        p = NULL;
}

void Copy(const char * a){
    if(p){
        delete []p;
        p = NULL;
    }
    if(a){
        p = new char[strlen(a) + 1];
        strcpy(p, a);
    }
}

operator char* (){
    return p;
}
/*
	MyString & operator=(const MyString &);
	MyString & operator=(const char *);
    MyString(MyString &);
	void Copy(const char * s);
    operator char* ();
	friend ostream & operator<<(ostream &, MyString &);
*/
};

/*
MyString & MyString::operator=(const MyString & a){
    if(p){
        delete []p;
        p = NULL;
    }
	if(a.p){
        p = new char[strlen(a.p) + 1];
        strcpy(p, a.p);
    }
    return *this;
}

MyString & MyString::operator=(const char * a){
    if(p){
        delete []p;
        p = NULL;
    }
	if(a){
        p = new char[strlen(a) + 1];
        strcpy(p, a);
    }
    return *this;
}

MyString::MyString(MyString & a){
    if(a.p){
        p = new char[strlen(a.p) + 1];
        strcpy(p, a.p);
    }
    else
        p = NULL;
}

void MyString::Copy(const char * a){
    if(p){
        delete []p;
        p = NULL;
    }
    if(a){
        p = new char[strlen(a) + 1];
        strcpy(p, a);
    }
}

MyString::operator char* (){
    return p;
}
*/

/*
ostream & operator<<(ostream &o, MyString &a){
	o << a.p;
	return o;
}
*/
int main()
{
	char w1[200],w2[100];
	freopen("test.txt", "r", stdin);
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}