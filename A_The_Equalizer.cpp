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

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            sum += x;
        }

        // Shaunak wins if either:
        // 1) he never uses special move and initial total moves is odd, or
        // 2) he uses special move immediately, making total n*k (Yash to move),
        //    so Shaunak wins when n*k is even.
        if ((sum % 2LL == 1LL) || ((1LL * n * k) % 2LL == 0LL)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
