#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

char map[1001][1001];
int fire[1001][1001];
int sang[1001][1001];

int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

int w, h;

queue<pair<int, int>> f_q;
queue<pair<int, int>> s_q;

void bfsFire() {
	while (!f_q.empty()) {
		int x = f_q.front().first;
		int y = f_q.front().second;
		f_q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (fire[nx][ny] != 0 || map[nx][ny] == '#') continue;
			fire[nx][ny] = fire[x][y] + 1;
			f_q.push({ nx, ny });
		}
	}
}

void escape() {
	while (!s_q.empty()) {
		int x = s_q.front().first;
		int y = s_q.front().second;
		s_q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				cout << sang[x][y] << '\n';
				return;
			}
			if (sang[nx][ny] != 0 || map[nx][ny] == '#') continue;
			if (sang[x][y] + 1 >= fire[nx][ny] && fire[nx][ny] != 0) continue;
			sang[nx][ny] = sang[x][y] + 1;
			s_q.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(fire, 0, sizeof(fire));
		memset(sang, 0, sizeof(sang));
		queue<pair<int, int>> init_s;
		s_q = init_s;
		queue<pair<int, int>> init_f;
		f_q = init_f;
		
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < str.size(); j++) {
				map[i][j] = str[j];
				if (str[j] == '@') {
					sang[i][j] = 1;
					s_q.push({ i, j });
				}
				if (str[j] == '*') {
					fire[i][j] = 1;
					f_q.push({ i, j });
				}
			}
		}
		bfsFire();
		escape();
	}
}