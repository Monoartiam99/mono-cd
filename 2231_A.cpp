#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    const int MAXP = 32;
    vector<long long> total(MAXP, LLONG_MAX);

    vector<long long> cost_sum(MAXP, 0);
    vector<bool> reachable(MAXP, true);

    for (int i = 0; i < n; i++) {
        long long x = a[i];
        int ops = 0;
    
        vector<bool> seen(MAXP, false);

        while (x != 0) {
          
            if ((x & (x - 1)) == 0) {
                int p = __builtin_ctzll(x);
                if (p < MAXP && !seen[p]) {
                    seen[p] = true;
                    cost_sum[p] += ops;
                }
            }
            if (x == 1) break;
            if (x & 1) { x++; ops++; }
            else { x >>= 1; ops++; }
        }

      
        for (int p = 0; p < MAXP; p++) {
            if (!seen[p]) reachable[p] = false;
        }
    }

    long long ans = LLONG_MAX;
    for (int p = 0; p < MAXP; p++) {
        if (reachable[p]) ans = min(ans, cost_sum[p]);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}