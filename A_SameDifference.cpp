#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        char target = s.back();
        int ans = 0;
        for (int i = 0; i + 1 < n; ++i) if (s[i] != target) ++ans;
        cout << ans << '\n';
    }

    return 0;
}
