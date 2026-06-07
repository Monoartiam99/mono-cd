#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        long long sum = 0;
        long long best = (1LL << 62);

        for(int i = 1; i <= n; i++) {
            long long a;
            cin >> a;
            sum += a;
            best = min(best, sum / i);

            cout << best << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}