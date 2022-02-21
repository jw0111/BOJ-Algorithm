#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string str;
	cin >> str;
	stack<char> s;

	int ans = 0;
	bool laser = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			laser = true;
		}
		else {
			s.pop();
			if (laser) {
				ans += s.size();
				laser = false;
			}
			else {
				ans += 1;
			}
		}
	}
	cout << ans;
}