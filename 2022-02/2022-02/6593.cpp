#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

char map[31][31][31];
int visit[31][31][31];

int l, r, c;

int mx[6] = { -1,1,0,0,0,0 };
int my[6] = { 0,0,-1,1,0,0 };
int mz[6] = { 0,0,0,0,-1,1 };

queue<tuple<int, int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		int z = get<0>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			int nz = z + mz[i];
			if (map[nz][nx][ny] == 'E') {
				cout << "Escaped in " << visit[z][x][y] << " minute(s).\n";
				return;
			}
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
			if (visit[nz][nx][ny] != 0 || map[nz][nx][ny] == '#') continue;
			visit[nz][nx][ny] = visit[z][x][y] + 1;
			q.push({ nz, nx, ny });
		}
	}
	cout << "Trapped!\n";
}

int main() {
	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		memset(visit, 0, sizeof(visit));
		queue<tuple<int, int, int>> init;
		q = init;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				string str;
				cin >> str;
				for (int k = 0; k < c; k++) {
					map[i][j][k] = str[k];
					if (str[k] == 'S') {
						q.push({ i, j, k });
						visit[i][j][k] = 1;
					}
				}
			}
		}
		bfs();
	}
}