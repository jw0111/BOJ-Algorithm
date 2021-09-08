#include <iostream>
using namespace std;

struct node {
	char left;
	char right;
};

node nodes[27];

void preorder(char n) {
	if (n == '.') return;
	cout << n;
	preorder(nodes[n].left);
	preorder(nodes[n].right);
}

void inorder(char n) {
	if (n == '.') return;
	inorder(nodes[n].left);
	cout << n;
	inorder(nodes[n].right);
}

void postorder(char n) {
	if (n == '.') return;
	postorder(nodes[n].left);
	postorder(nodes[n].right);
	cout << n;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		nodes[a].left = b;
		nodes[a].right = c;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
}