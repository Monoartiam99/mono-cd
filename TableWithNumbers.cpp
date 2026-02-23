#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;
        int row = 0, col = 0, both = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            bool r = (x <= h);
            bool c = (x <= l);
            if (r && c) both++;
            else if (r) row++;
            else if (c) col++;
        }
        int ans = min(row, col);
        int left = abs(row - col);
        int use = min(left, both);
        ans += use;
        both -= use;
        ans += both / 2;
        cout << ans << "\n";
    }
    return 0;
}
