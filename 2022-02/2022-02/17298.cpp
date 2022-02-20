#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int arr[1000001];
int ans[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(ans, -1, sizeof(ans));
	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[i] > arr[s.top()]){
			ans[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}