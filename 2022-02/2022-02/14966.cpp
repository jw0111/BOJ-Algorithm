#include <iostream>
using namespace std;

pair<int, int> hilbert(int n, int m) {
	if (n == 2) {
		if (m == 0) return { 1,1 };
		else if (m == 1) return { 1,2 };
		else if (m == 2) return { 2,2 };
		else if (m == 3) return { 2,1 };
	}
	int half = n / 2;
	int quad = m / (half * half);
	pair <int, int> p;
	p = hilbert(half, m % (half * half));
	if (quad == 0) {
		swap(p.first, p.second);
		return p;
	}
	else if (quad == 1) {
		p.second += half;
		return p;
	}
	else if (quad == 2) {
		p.first += half;
		p.second += half;
		return p;
	}
	else if (quad == 3) {
		pair<int, int> tmp = { 2 * half - p.second + 1, half - p.first + 1 };
		return tmp;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	pair<int, int> ans = hilbert(n, m - 1);
	cout << ans.first << " " << ans.second;
}