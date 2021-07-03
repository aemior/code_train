#include <iostream>

using namespace std;

char puzzle[5][6];

void findblank(int &x, int &y) {
	for (int i=0; i<5; ++i) {
		for (int j=0; j<5; ++j) {
			if (puzzle[i][j] == ' ' || !puzzle[i][j]) {
				x = j;
				y = i;
				return;
			}
		}
	}
}

int main () {
	//freopen("test.txt", "r", stdin);
	int cnt=0;
	int x,y;
	char t = cin.peek();
	while (t != 'Z')
	{
		for (int i=0; i<5; ++i) {
			cin.getline(puzzle[i], 6);
		}
		cout << "Puzzle #" << ++cnt << ':' << endl;
		bool flg = true;
		t = cin.peek();
		while (t != '0') {
			t = cin.get();
			if (t == '\n') {
				t = cin.peek();
				continue;
			}
			findblank(x,y);
			switch (t)
			{
			case 'A':
				if (y == 0) {
					flg = false;
				} else {
					puzzle[y][x] = puzzle[y-1][x];
					puzzle[y-1][x] = ' ';
				}
				break;
			case 'B':
				if (y == 4) {
					flg = false;
				} else {
					puzzle[y][x] = puzzle[y+1][x];
					puzzle[y+1][x] = ' ';
				}
				break;
			case 'L':
				if (x == 0) {
					flg = false;
				} else {
					puzzle[y][x] = puzzle[y][x-1];
					puzzle[y][x-1] = ' ';
				}
				break;
			case 'R':
				if (x == 4) {
					flg = false;
				} else {
					puzzle[y][x] = puzzle[y][x+1];
					puzzle[y][x+1] = ' ';
				}
				break;
			default:
				break;
			}
			t = cin.peek();
		}
		if (flg) {
			for (int i=0; i<5; ++i) {
				for (int j=0; j<5; ++j) {
					cout << puzzle[i][j];
					if (j != 4) cout << ' ';
				}
				cout << endl;
			}

		} else {
			cout << "This puzzle has no final configuration." << endl;
		}
		cin.get();
		cin.get();
		t = cin.peek();
		if (t != 'Z')
			cout << endl;
	}
	return 0;
}