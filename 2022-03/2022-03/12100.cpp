#include <iostream>
using namespace std;

int board1[21][21];
int board2[21][21];
int N;

void rotate() {
	int tmp[21][21];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmp[i][j] = board2[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board2[i][j] = tmp[N - 1 - j][i];
}

void tilt(int dir) {
	while (dir--) rotate();
	for (int i = 0; i < N; i++) {
		int idx = 0;
		int tilted[21] = {};
		for (int j = 0; j < N; j++) {
			if (board2[i][j] == 0) continue;
			if (tilted[idx] == 0) tilted[idx] = board2[i][j];
			else if (tilted[idx] == board2[i][j])
				tilted[idx++] *= 2;
			else tilted[++idx] = board2[i][j];
		}
		for (int j = 0; j < N; j++)
			board2[i][j] = tilted[j];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board1[i][j];
	for (int tmp = 0; tmp < 1024; tmp++) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board2[i][j] = board1[i][j];
		int brute = tmp;
		for (int i = 0; i <= 4; i++) {
			int dir = brute % 4;
			brute /= 4;
			tilt(dir);
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans = max(ans, board2[i][j]);
	}
	cout << ans;
}