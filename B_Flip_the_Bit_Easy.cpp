#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        int p;
        cin >> p; // k = 1 in easy version

        int x = a[p];

        int leftOps = 0;
        if (p > 1) {
            int prev = a[1] ^ x;
            leftOps += prev;
            for (int i = 2; i <= p - 1; ++i) {
                int cur = a[i] ^ x;
                if (cur != prev) {
                    ++leftOps;
                }
                prev = cur;
            }
        }

        int rightOps = 0;
        if (p < n) {
            int prev = a[p + 1] ^ x;
            for (int i = p + 2; i <= n; ++i) {
                int cur = a[i] ^ x;
                if (cur != prev) {
                    ++rightOps;
                }
                prev = cur;
            }
            rightOps += (a[n] ^ x);
        }

        int need = max(leftOps, rightOps);
        if (need % 2 == 1) {
            ++need;
        }

        cout << need << '\n';
    }

    return 0;
}
