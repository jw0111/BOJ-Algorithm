#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[9];
int visit[9];
vector<int> vec;
vector<vector<int>> ans;

void sol(int cnt, int idx) {
	if (cnt == M) {
		vector<int> s;
		for (int i = 0; i < M; i++)
			s.push_back(arr[i]);
		ans.push_back(s);
	}
	for (int i = idx; i < vec.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = vec[i];
			sol(cnt + 1, idx);
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
	sol(0, 0);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (auto& ele : ans) {
		for (int i = 0; i < ele.size(); i++)
			cout << ele[i] << " ";
		cout << '\n';
	}
}