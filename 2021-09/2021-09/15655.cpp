#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[9];
int visit[9];
vector<int> vec;


void sol(int cnt, int idx) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = idx; i < vec.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = vec[i];
			sol(cnt + 1, i + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	sol(0, 0);
}