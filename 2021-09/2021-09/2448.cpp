#include <iostream>
#include <vector>

using namespace std;

bool board[10001][10001];

void star(int n, int x, int y) {
	if (n == 3) {
		board[x][y] = true;
		board[x + 1][y - 1] = true;
		board[x + 1][y + 1] = true;
		for (int i = 0; i < 5; i++) {
			board[x + 2][y - i + 2] = true;
		}
		return;
	}

	star(n / 2, x, y); 
	star(n / 2, x + n / 2, y - n / 2);
	star(n / 2, x + n / 2, y + n / 2);
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	star(N, 0, N - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (board[i][j]) cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}
}