#include <iostream>
#include <string>
#include <queue>
using namespace std;

char maze[1002][1002];
int fire[1002][1002];
int jihun[1002][1002];
queue<pair<int, int>> q_f;
queue<pair<int, int>> q_j;

int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

int r, c;

void bfsFire() {
	while (!q_f.empty()) {
		int x = q_f.front().first;
		int y = q_f.front().second;
		q_f.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (fire[nx][ny] != 0 || maze[nx][ny] == '#') continue;
			fire[nx][ny] = fire[x][y] + 1;
			q_f.push({ nx, ny });
		}
	}
}

void escape() {
	while (!q_j.empty()) {
		int x = q_j.front().first;
		int y = q_j.front().second;
		q_j.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << jihun[x][y];
				return;
			}
			if (jihun[nx][ny] != 0 || maze[nx][ny] == '#') continue;
			if (jihun[x][y] + 1 >= fire[nx][ny] && fire[nx][ny] != 0) continue;
			q_j.push({ nx, ny });
			jihun[nx][ny] = jihun[x][y] + 1;
		}
	}
	cout << "IMPOSSIBLE";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			maze[i][j] = str[j];
			if (maze[i][j] == 'F') {
				q_f.push({ i, j });
				fire[i][j] = 1;
			}
			if (maze[i][j] == 'J') {
				q_j.push({ i, j });
				jihun[i][j] = 1;
			}
		}
	}
	bfsFire();
	escape();
}