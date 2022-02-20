#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int top[500001];
int ans[500001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(ans, -1, sizeof(ans));

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> top[i];
	}
	stack<int> s;

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && top[i] > top[s.top()]) {
			ans[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1 << " ";
	}
}