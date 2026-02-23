#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        int first; cin >> first;
        int pref_max = first;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int x; cin >> x;
            if (x < pref_max) {
                ++ans; // deletable because some earlier element (pref_max) is greater
            } else {
                pref_max = x; // update maximum seen so far
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
