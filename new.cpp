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

        vector<int> freq(n * n + 1, 0);
        int maxFrequency = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int color;
                cin >> color;
                maxFrequency = max(maxFrequency, ++freq[color]);
            }
        }

        cout << (maxFrequency <= n * (n - 1) ? "YES" : "NO") << '\n';
    }

    return 0;
}


