#include <iostream>
using namespace std;

int n, s;
int num[21];
int ans = 0;

void func(int tmp, int tot) {
	if (tmp == n) {
		if(tot == s) ans++;
		return;
	}
	func(tmp + 1, tot);
	func(tmp + 1, tot + num[tmp]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	func(0, 0);
	if (s == 0) ans -= 1;
	cout << ans;
}
