#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;
bool visit[9];
int arr[9];

void sol(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[idx] = vec[i];
			sol(idx + 1);
			visit[i] = false;
		}
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

	sol(0);
}