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

        vector<int> ans;

        if (n % 2 == 0) {
            // Matches the sample style for even n: 2, n, n-1, ..., 3, 1
            ans.push_back(2);
            for (int x = n; x >= 3; --x) {
                ans.push_back(x);
            }
            ans.push_back(1);
        } else {
            if (n == 3) {
                ans = {2, 3, 1};
            } else {
                // Matches the sample style for odd n >= 5: 3, n, n-1, ..., 4, 2, 1
                ans.push_back(3);
                for (int x = n; x >= 4; --x) {
                    ans.push_back(x);
                }
                ans.push_back(2);
                ans.push_back(1);
            }
        }

        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i] << (i + 1 == (int)ans.size() ? '\n' : ' ');
        }
    }

    return 0;
}
