#include <iostream>
#include <vector>

using namespace std;

int main() {
	string direction;
	vector<string> turns;
	int x = 500, y = 500, maxx = 500, maxy = 500, minx = 500, miny = 500;	
	while (cin >> direction) {
		turns.push_back(direction);
	}
	char path[1000][1000];
	path[500][500] = 'S';
	for (int i = 0; i < turns.size(); i++) {
		if (turns[i] == "up") {
			x--;
		}
		if (turns[i] == "down") {
			x++;
		}
		if (turns[i] == "left") {
			y--;
		}
		if (turns[i] == "right") {
			y++;
		}
		
		if (x > maxx) {
			maxx = x;
		}
		if (x < minx) {
			minx = x;
		}
		if (y > maxy) {
			maxy = y;
		}
		if (y < miny) {
			miny = y;
		}
		if (path[x][y] != 'S') {
			path[x][y] = '*';
		}
	}
	path[x][y] = 'E';
	for (int i = minx; i <= maxx; i++) {
		for (int j = miny; j <= maxy; j++) {
			if (path[i][j] == (char)0) {
				path[i][j] = ' ';
			}
		}
	}
	for (int i = minx - 1; i <= maxx + 1; i++) {
		for (int j = miny - 1; j <= maxy + 1; j++) {
			if (path[i][j] == (char)0) {
				path[i][j] = '#';
			}
		}
	}
	for (int i = minx - 1; i <= maxx + 1; i++) {
		for (int j = miny - 1; j <= maxy + 1; j++) {
			cout << path[i][j];
		}
		cout << endl;
	}
}
