#include <bits/stdc++.h>
using namespace std;

static constexpr int MAXN = 3000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x, s;
        cin >> n >> x >> s;

        string eia;
        cin >> eia;

        vector<bitset<MAXN + 1>> dp(x + 1), next_dp(x + 1);
        dp[0].set(0);

        for (char c : eia) {
            next_dp = dp;

            for (int used = 0; used <= x; ++used) {
                if ((c == 'E' || c == 'A') && dp[used].any()) {
                    next_dp[used] |= (dp[used] >> 1);
                }

                if ((c == 'I' || c == 'A') && used < x && dp[used].any()) {
                    next_dp[used + 1] |= (dp[used] << (s - 1));
                }
            }

            dp.swap(next_dp);
        }

        int answer = 0;
        for (int used = 0; used <= x; ++used) {
            for (int remaining = 0; remaining <= n; ++remaining) {
                if (dp[used][remaining]) {
                    answer = max(answer, used * s - remaining);
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}