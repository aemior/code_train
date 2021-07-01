#include <bits/stdc++.h>

using namespace std;

float poland(){
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
		break;
	}
	return atof(buf);
}

int main(){
	float v = poland();
	printf("%f\n", v);
	return 0;
}