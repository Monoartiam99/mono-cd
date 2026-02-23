//https://codeforces.com/problemset/problem/1881/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        string cur = x;
        int ans = -1;
        for (int k = 0; k <= 6; k++) {
            if (cur.find(s) != string::npos) {
                ans = k;
                break;
            }
            cur += cur; // perform operation
        }
        cout << ans << "\n";
    }
    return 0;
}
