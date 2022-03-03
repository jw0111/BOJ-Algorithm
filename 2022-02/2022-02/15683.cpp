#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int map[10][10];
vector<pair<int, int>> cctv;

int N, M;
int ans = 987654321;

void init(int copy[][10], int origin[][10]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

void left(int x, int y) {
	for (int i = y; i >= 0; i--) {
		if (map[x][i] == 6)
			break;
		else {
			if (map[x][i] == 0) {
				map[x][i] = 9;
			}
		}
	}
}
void right(int x, int y) {
	for (int i = y; i < M; i++) {
		if (map[x][i] == 6)
			break;
		else {
			if (map[x][i] == 0) {
				map[x][i] = 9;
			}
		}
	}
}
void up(int x, int y) {
	for (int i = x; i < N; i++) {
		if (map[i][y] == 6)
			break;
		else {
			if (map[i][y] == 0) {
				map[i][y] = 9;
			}
		}
	}
}
void down(int x, int y) {
	for (int i = x; i >= 0; i--) {
		if (map[i][y] == 6)
			break;
		else {
			if (map[i][y] == 0) {
				map[i][y] = 9;
			}
		}
	}
}
void check(int num) {
	if (num == cctv.size()) {
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					tmp++;
			}
		}
		ans = min(ans, tmp);
		return;
	}

	int backup[10][10];
	int x = cctv[num].first;
	int y = cctv[num].second;
	for (int dir = 0; dir < 4; dir++) {
		init(backup, map);
		if (map[x][y] == 1) {
			if (dir == 0) left(x, y);
			else if (dir == 1) right(x, y);
			else if (dir == 2) up(x, y);
			else if (dir == 3) down(x, y);
		}
		else if (map[x][y] == 2) {
			if (dir == 0 || dir == 2) {
				left(x, y); right(x, y);
			}
			else {
				up(x, y); down(x, y);
			}
		}
		else if (map[x][y] == 3) {
			if (dir == 0) {
				up(x, y); right(x, y);
			}
			else if (dir == 1) {
				right(x, y); down(x, y);
			}
			else if (dir == 2) {
				down(x, y); left(x, y);
			}
			else if (dir == 3) {
				left(x, y); up(x, y);
			}
		}
		else if (map[x][y] == 4) {
			if (dir == 0) {
				right(x, y); up(x, y); left(x, y);
			}
			else if (dir == 1) {
				up(x, y); right(x, y); down(x, y);
			}
			else if (dir == 2) {
				right(x, y); down(x, y); left(x, y);
			}
			else if (dir == 3) {
				down(x, y); left(x, y); up(x, y);
			}
		}
		else if (map[x][y] == 5) {
			up(x, y); right(x, y); down(x, y); left(x, y);
		}
		check(num + 1);
		init(map, backup);
	}
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 6 && map[i][j] != 0)
				cctv.push_back({ i, j });
		}
	}
	if (!cctv.empty())
		check(0);
	else {
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					tmp++;
			}
		}
		ans = tmp;
	}
	cout << ans;
}