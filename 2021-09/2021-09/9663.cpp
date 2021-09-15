#include <iostream>
using namespace std;

int col[15];
int N, ans = 0;

bool check(int level) {
    for (int i = 0; i < level; i++)
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)// 대각선이거나 같은 라인
            return false;
    return true;
}

void sol(int x) {
    if (x == N)
        ans++;
    else {
        for (int i = 0; i < N; i++) {
            col[x] = i;
            if (check(x)) 
                sol(x + 1);
        }
    }
}
int main() {
    cin >> N;
    sol(0);
    cout << ans;
}