#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[9][9];
int tmp[9][9];
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };
int ans = 0;

void bfs() {
    int map2[9][9];
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            map2[i][j] = tmp[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map2[i][j] == 2) q.push({i, j});

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = a + mx[i];
            int ny = b + my[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) { 
                if (map2[nx][ny] == 0) { 
                    map2[nx][ny] = 2; 
                    q.push({nx, ny});
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map2[i][j] == 0) cnt++;
    ans = max(ans, cnt);
}

void simulation(int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                simulation(cnt + 1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == 0) {
                for (int k = 0; k < N; k++) {
                    for (int l = 0; l < M; l++) {
                        tmp[k][l] = map[k][l];
                    }
                }
                tmp[i][j] = 1; 
                simulation(1); 
                tmp[i][j] = 0; 
            }
    cout << ans << '\n';
}