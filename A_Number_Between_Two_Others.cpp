#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x, y;
        cin >> x >> y;

        cout << ((y == 2 * x) ? "NO\n" : "YES\n");
    }

    return 0;
}
