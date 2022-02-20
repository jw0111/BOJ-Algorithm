#include <iostream>
using namespace std;

int schedule[101], plug[101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < K; i++)
        cin >> schedule[i];

    int ans = 0;

    for (int i = 0; i < K; i++) {
        bool flag = false;
        for (int j = 0; j < N; j++)
            if (plug[j] == schedule[i]) {
                flag = true;
                break;
            }
         if (flag)
            continue;

        for (int j = 0; j < N; j++)
            if (!plug[j]) {
                plug[j] = schedule[i];
                flag = true;
                break;
            }
        if (flag)
           continue;

        int idx, deviceIdx = -1;
        for (int j = 0; j < N; j++) {
            int last = 0;
            for (int k = i + 1; k < K; k++) {
                if (plug[j] == schedule[k]) break;
                last++;
            }
            if (last > deviceIdx) {
                idx = j;
                deviceIdx = last;
            }
        }
        ans++;
        plug[idx] = schedule[i];
    }
    cout << ans;
}