#include <bits/stdc++.h>

using namespace std;

int factor_value ();
int experssion_value();
int term_value();

int main () {
	cout << experssion_value() << endl;
	return 0;
}

int factor_value () {
	char t = cin.peek();
	int res = 0;
	if (t == '(') {
		cin.get();
		res = experssion_value();
		cin.get();
	} else {
		while (t <= '9' && t >= '0') {
			res = res * 10 + (t - '0');
			cin.get();
			t = cin.peek();
		}
	}
	return res;
}

int term_value() {
	int res = factor_value();
	char t = cin.peek();
	while (t == '*' || t == '/') {
		cin.get();
		int f = factor_value();
		if (t == '*') {
			res = f*res;
		} else {
			res = res/f;
		}
		t = cin.peek();
	}
	return res;
}

int experssion_value () {
	int res = term_value();
	char t = cin.peek();
	while (t == '+' || t == '-') {
		cin.get();
		if (t == '+') {
			res =  res + term_value();
		} else {
			res =  res - term_value();
		}
		t = cin.peek();
	}
	return res;
}