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
        string s;
        cin >> s;

        // pad with '1' on both sides
        s = "1" + s + "1";

        int ans = 0;

        // count initial students
        for (char c : s)
            if (c == '1') ans++;

        // greedy placement
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0' && s[i - 1] == '0' && s[i + 1] == '0') {
                s[i] = '1';
                ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
