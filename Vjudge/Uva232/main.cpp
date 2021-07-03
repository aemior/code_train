#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

char puzzle[11][11];
int ID[10][10];

int main () {
	//freopen("test.txt", "r", stdin);
	int M, N;
	int C=0;
	while (cin.peek() != '0')
	{
		cout << "puzzle #" << ++C << '.' << endl;
		cin >> M >> N;
		cin.get();
		for (int i=0; i<M; ++i) {
			cin.getline(puzzle[i], N+2);
			memset(ID[i], 0, sizeof(ID[i]));
		}
		int cnt = 0;
		for (int i=0; i<M; ++i) {
			for (int j=0; j<N; ++j) {
				if (puzzle[i][j] == '*') continue; 
				if (i == 0 || j == 0) {
					ID[i][j] = ++cnt;
				} else if (puzzle[i-1][j] == '*' || puzzle[i][j-1] == '*') {
					ID[i][j] = ++cnt;
				}
			}
		}
		cout << "Across" << endl;
		for (int k=1; k<=cnt; ++k) {
			for (int i=0; i<M; ++i) {
				for (int j=0; j<N; ++j) {
					if (ID[i][j] == k) {
						bool flg = false;
						if (j == 0) {
							flg = true;
						} else if (puzzle[i][j-1] == '*') {
							flg = true;
						}
						if (flg){
							cout << setw(3) << ID[i][j] << '.';
							for (; j<N && puzzle[i][j] != '*'; ++j) {
								cout << puzzle[i][j];
							}
							cout << endl;
						}
					}
				}
			}
		}
		cout << "Down" << endl;
		for (int k=1; k<=cnt; ++k) {
			for (int j=0; j<N; ++j) {
				for (int i=0; i<M; ++i) {
					if (ID[i][j] == k) {
						bool flg = false;
						if (i == 0) {
							flg = true;
						} else if (puzzle[i-1][j] == '*') {
							flg = true;
						}
						if (flg){
							cout << setw(3) << ID[i][j] << '.';
							for (; i<M && puzzle[i][j] != '*'; ++i) {
								cout << puzzle[i][j];
							}
							cout << endl;
						}
					}
				}
			}
		}
		if (cin.peek() != '0')
			cout << endl;
	}
	
	return 0;
}