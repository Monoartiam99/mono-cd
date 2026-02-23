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

        vector<int> p(n), a(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> a[i];

        bool ok = true;

        for(int i = 0; i < n; i++) {
            if(a[i] == p[i]) continue;

            bool can = false;

            if(i > 0 && a[i] == a[i-1]) can = true;
            if(i < n-1 && a[i] == a[i+1]) can = true;

            if(!can) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
