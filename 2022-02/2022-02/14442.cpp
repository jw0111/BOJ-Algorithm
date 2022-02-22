#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>
using namespace std;

int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

int map[1001][1001];
int tmp[1001][1001];
int visit[1001][1001][11];
int N, M, K;
queue <tuple<int, int, int>> q;
int ans = 987654321;

void bfs() {
	memset(visit, 0, sizeof(visit));
	q.push({ 0, 0, K });
	visit[0][0][K] = 1;
	while (!q.empty()) {
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + mx[i];
			int ny = b + my[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (nx == N - 1 && ny == M - 1) {
					visit[nx][ny][c] = visit[a][b][c] + 1;
					ans = min(ans, visit[nx][ny][c]);
				}
				if (!visit[nx][ny][c - 1] && map[nx][ny] == 1 && c > 0) {
					visit[nx][ny][c - 1] = visit[a][b][c] + 1;
					q.push({ nx, ny, c - 1 });
				}
				if (!visit[nx][ny][c] && map[nx][ny] == 0) {
					visit[nx][ny][c] = visit[a][b][c] + 1;
					q.push({ nx, ny, c });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = int(s[j] - '0');
		}
	}
	if (N == 1 && M == 1) {
		if (map[0][0] == 0) {
			ans = 1;
			cout << ans;
			return 0;
		}
	}
	bfs();
	if (ans == 987654321) {
		cout << "-1";
		return 0;
	}
	cout << ans;
}