#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];
int N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		sum = max(sum, dp[i]);
	}

	cout << sum << '\n';
}