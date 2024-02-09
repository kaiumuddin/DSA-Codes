#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> marks(N);
        for (int i = 0; i < N; ++i) {
            cin >> marks[i];
        }

        vector<bool> dp(M + 1, false);
        dp[0] = true;

        for (int i = 0; i < N; ++i) {
            for (int j = marks[i]; j <= M; ++j) {
                dp[j] = dp[j] || dp[j - marks[i]];
            }
        }

        if (dp[M]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
