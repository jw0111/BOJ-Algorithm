#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[55][55];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back({ i, j });
			if (map[i][j] == 2)
				chicken.push_back({ i, j });
		}
	}
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - M, 0);
	int ans = 0x7f7f7f;
	do {
		int dist = 0;
		for (auto h : house) {
			int tmp = 0x7f7f7f;
			for (int i = 0; i < chicken.size(); i++) {
				if (brute[i] == 0) continue;
				tmp = min(tmp, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
			}
			dist += tmp;
		}
		ans = min(ans, dist);
	} while (next_permutation(brute.begin(), brute.end()));
	cout << ans;
}