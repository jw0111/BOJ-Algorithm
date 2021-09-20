#include <iostream>
using namespace std;

int stair[301];
int dp[301];
int N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int scr; cin >> scr;
		stair[i] = scr;
	}
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
	}
	cout << dp[N];
}