#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int equal_adjacent = 0;
        for (int i = 0; i + 1 < (int)s.size(); ++i) {
            if (s[i] == s[i + 1]) {
                ++equal_adjacent;
            }
        }

        cout << (equal_adjacent <= 2 ? "YES\n" : "NO\n");
    }

    return 0;
}
