#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> 
using namespace std;

int N, M;
string arr[101][101];

string addBig(string num1, string num2) {
    long long sum = 0;
    string result;
    while (!num1.empty() || !num2.empty() || sum) {
        if (!num1.empty()) {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}
string combination(int n, int r) {
    if (n == r || r == 0)
        return "1";

    string& result = arr[n][r];
    if (result != "")
        return result;

    result = addBig(combination(n - 1, r - 1), combination(n - 1, r));
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cout << combination(N, M) << '\n';

    return 0;
}