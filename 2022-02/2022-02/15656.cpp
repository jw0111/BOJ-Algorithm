#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;
bool visit[9];
int arr[9];

void sol(int cnt, int idx) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		visit[i] = true;
		arr[cnt] = vec[i];
		sol(cnt + 1, i);
		visit[i] = false;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	sol(0, 0);
}