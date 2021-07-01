#include <bits/stdc++.h>

using namespace std;

double poland(){
	char buf[40];
	cin >> buf;
	switch (buf[0])
	{
	case '+':
		return poland() + poland();
	case '-':
		return poland() - poland();
	case '*':
		return poland() * poland();
	case '/':
		return poland() / poland();
	default:
		return atof(buf);
		break;
	}
}

int main(){
	double v = poland();
	printf("%f\n", v);
	return 0;
}