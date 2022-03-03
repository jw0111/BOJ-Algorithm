#include <iostream>
using namespace std;

int note[50][50];
int sticker[12][12];
int N, M, K;
int r, c;

bool patch(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (note[i+x][j+y] == 1 && sticker[i][j] == 1)
				return false;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j]) note[i + x][j + y] = 1;
		}
	}
	return true;
}

void rotate() {
	int tmp[12][12];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp[i][j] = sticker[i][j];
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++)
			sticker[i][j] = tmp[r - 1 - j][i];
	}
	swap(r, c);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M >> K;
	while (K--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cin >> sticker[i][j];
		}
		for (int rot = 0; rot < 4; rot++) {
			bool isPatched = false;
			for (int i = 0; i <= N - r; i++) {
				if (isPatched) break;
				for (int j = 0; j <= M - c; j++) {
					if (patch(i, j)) {
						isPatched = true;
						break;
					}
				}
			}
			if (isPatched) break;
			rotate();
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (note[i][j]) ans++;
		}
	}
	cout << ans << '\n';
}