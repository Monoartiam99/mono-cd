#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long x;
        cin >> x;

        long long L = a[0], R = a[0];
        for (int i = 1; i < n; i++) {
            L = min(L, a[i]);
            R = max(R, a[i]);
        }

        if (x >= L && x <= R) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
