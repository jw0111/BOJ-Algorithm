#include <iostream>
using namespace std;

int triangle[501][501];
int ans[501][501];

int maximum = 0;

int main() {
	int  n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == 1) {
				ans[i][j] = triangle[i][j];
				continue;
			}
			if (j == 1)
				ans[i][j] = ans[i - 1][j] + triangle[i][j];
			else if (j == i) {
				ans[i][j] = ans[i - 1][j - 1] + triangle[i][j];
			}
			else {
				ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + triangle[i][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (ans[n][i] > maximum)
			maximum = ans[n][i];
	}

	cout << maximum;
	return 0;
}