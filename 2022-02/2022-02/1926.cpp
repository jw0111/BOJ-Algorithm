#include <iostream>
#include <queue>
using namespace std;

int paper[501][501];
int visit[501][501];

int n, m;

int mx[4] = { -1, 0, 1, 0 };
int my[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q_f;

int bfs(int sx, int sy) {
	int size = 0;
	while (!q_f.empty()) {
		int x = q_f.front().first;
		int y = q_f.front().second;
		q_f.pop();
		size++;
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (paper[nx][ny] == 0 || visit[nx][ny]) continue;
			visit[nx][ny] = true;
			q_f.push({ nx, ny });
		}
	}
	return size;
}
int main() {
	int cnt = 0, max_size = 0;
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] == 1 && !visit[i][j]) {
				q_f.push({ i,j });
				visit[i][j] = true;
				int cur_size = bfs(i, j);
				max_size = max_size < cur_size ? cur_size : max_size;
				cnt++;
			}
		}
	}
	
	cout << cnt << '\n' << max_size;
}