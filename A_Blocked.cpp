#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) return 0;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.rbegin(), a.rend());

        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }

    return 0;
}