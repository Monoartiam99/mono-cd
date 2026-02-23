#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int diff = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) diff++;
        }

        if (s[0] != s[n - 1]) diff++;

        if (diff == 0) cout << 1 << "\n";
        else cout << diff << "\n";
    }
}