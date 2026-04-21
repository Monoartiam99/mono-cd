#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n + 1), pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        // freqTarget[x] = how many forward moves i -> p[i] have target x (i < p[i]).
        vector<int> freqTarget(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (p[i] > i) {
                ++freqTarget[p[i]];
            }
        }

        vector<int> pref(n + 1, 0);
        for (int x = 1; x <= n; ++x) {
            pref[x] = pref[x - 1] + freqTarget[x];
        }

        auto countIfStopAt = [&](int D) -> int {
            // Chairs visited before stop: 1..D-1.
            // We must skip exactly those i with i < p[i] < D.
            return (D - 1) - pref[D - 1];
        };

        // Option 1: never trigger an early marked chair (stop at n+1 naturally).
        int answer = countIfStopAt(n + 1);

        // Option 2: first marked chair is D (2 <= D <= n).
        for (int D = 2; D <= n; ++D) {
            // D is reachable as first marked chair iff some earlier index maps to D.
            if (pos[D] < D) {
                answer = max(answer, countIfStopAt(D));
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
