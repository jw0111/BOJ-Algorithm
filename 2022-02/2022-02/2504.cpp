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
	int tmp = 1;
	bool isValid = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			tmp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			tmp *= 3;
			s.push('[');
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				isValid = false;
				break;
			}
			if(str[i-1] == '(') ans += tmp;
			tmp /= 2;
			s.pop();
		}
		else {
			if (s.empty() || s.top() != '[') {
				isValid = false;
				break;
			}
			if (str[i - 1] == '[') ans += tmp;
			tmp /= 3;
			s.pop();
		}
	}
	if (!s.empty() || !isValid)
		cout << 0;
	else cout << ans;
}