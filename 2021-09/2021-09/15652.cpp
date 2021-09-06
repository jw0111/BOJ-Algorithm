// N과 M(4), 백트래킹?
#include <iostream>
using namespace std;

int N, M;
int arr[9];
bool visit[9];

void sol(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i <= N; i++) {
		visit[i] = true;
		arr[cnt] = i;
		sol(i, cnt + 1);
		visit[i] = false;
	}
}

int main() {
	cin >> N >> M;
	sol(1, 0);
}