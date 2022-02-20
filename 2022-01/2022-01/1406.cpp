#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	list<char> editor;
	string s;
	cin >> s;
	for (auto e : s) {
		editor.push_back(e);
	}
	list<char>::iterator iter;
	iter = editor.end();
	int m;
	cin >> m;
	while (m--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (iter != editor.begin()) {
				iter--;
			}
		}
		if (cmd == 'D') {
			if (iter != editor.end())
				iter++;
		}
		if (cmd == 'B') {
			if (iter != editor.begin()) {
				iter--;
				iter = editor.erase(iter);
			}
		}
		if (cmd == 'P') {
			char c;
			cin >> c;
			editor.insert(iter, c);
		}
	}
	for (auto e : editor) {
		cout << e;
	}
}