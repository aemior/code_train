#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
	private:
		char *data;
		int len;
		void replaceString(const char *sget, int lget){
			if (len) {
				delete [] data;
			}
			len = lget;
			if (len) {
				data = new char[len + 1];
				strcpy(data, sget);
			}
		}
	public:
		MyString():len(0){};
		MyString(const char *sget){
			len = strlen(sget);
			if (len) {
				data = new char[len + 1];
				strcpy(data, sget);
			}
		}
		MyString(const MyString &msget){
			len = msget.len;
			if (len) {
				data = new char[len + 1];
				strcpy(data, msget.data);
			}
		}
		~MyString(){
			if (len) {
				delete [] data;
			}
		}
		int length(){return len;};
		friend ostream & operator<<(ostream &o, const MyString &ms){
			if (ms.len)
				o << ms.data;
			return o;
		}
		MyString & operator=(MyString  ms){
			replaceString(ms.data, ms.len);
			return *this;
		}
		MyString & operator=(const char *sget){
			replaceString(sget, strlen(sget));
			return *this;
		}
		MyString operator+(const char *sget){
			MyString res(*this);
			int nlen = strlen(sget);
			if (nlen) {
				char *tmp = res.data;
				res.data = new char[nlen + res.len + 1];
				strcpy(res.data, tmp);
				strcpy(res.data+res.len, sget);
				if (res.len) {
					delete [] tmp;
				}
			}
			res.len += nlen;
			return res;
		}
		MyString operator+(const MyString &ms){
			return *this + ms.data;
		}
		friend MyString operator+(const char *sget, MyString &ms){
			MyString tmp(sget);
			return tmp + ms;
		}
		bool operator==(const MyString &ms){
			if (len != ms.len) {
				return false;
			}
			else{
				return !strcmp(data, ms.data);
			}
		}
		bool operator<(const MyString &ms){
			int res = strcmp(data, ms.data);
			if (res == -1) {
				return true;
			}
			else {
				return false;
			}
		}
		bool operator>(const MyString &ms){
			int res = strcmp(data, ms.data);
			if (res == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		MyString operator()(int a, int l){
			if (!l) {
				return MyString();
			}
			else {
				char *tmp = new char[len+1];
				strcpy(tmp, data+a);
				tmp[l] = 0;
				MyString res(tmp);
				delete [] tmp;
				return res;
			}
		}
		void operator+=(const char *sget){
			int nlen = strlen(sget);
			if (nlen) {
				char *tmp = data;
				data = new char[len + nlen + 1];
				strcpy(data, tmp);
				strcpy(data+len, sget);
				if (len)
					delete [] tmp;
			}
			len += nlen;
		}
		char & operator[](int idx){
			return data[idx];
		}

// 在此处补充你的代码
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << s2;
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}