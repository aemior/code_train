#include <bits/stdc++.h>

using namespace std;

bool isOk(int I){
	for (int i=2; i<I; ++i) {
		if (I % i == 0) return false;
	}
	return true;
}

int main () {

	int N, cnt=0, init;
	bool OK[100005];
	memset(OK, 1, sizeof(OK));
	cin >> N;
	for (int i=2; i<N; ++i)
		for (int j=2*i; j<N; j+=i)
			OK[j] = false;
	for (init = 3; init <= N-2; init+=2) {
		//if (OK[init] && OK[init+2])
		if (OK[init] && OK[init+2] && isOk(init) && isOk(init+2))
		{
			cnt++;
			//cout << init << ' ' << init+2 << endl;
		} 
	}
	cout << cnt;
	return 0;
}