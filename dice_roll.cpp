#include <bits/stdc++.h>
using namespace std;

bool adjacent(int a, int b) {
    // Two sides are adjacent if they're different and not opposite
    return a != b && a + b != 7;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        // dp[i][j] = min changes for first i elements with i-th being j
        vector<vector<int>> dp(n + 1, vector<int>(7, INT_MAX));
        
        // Base case: first element
        for (int j = 1; j <= 6; j++) {
            dp[1][j] = (a[1] == j) ? 0 : 1;
        }
        
        // Fill DP table
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= 6; j++) {
                // Cost of making position i value j
                int cost = (a[i] == j) ? 0 : 1;
                
                // Try all possible previous values
                for (int k = 1; k <= 6; k++) {
                    if (adjacent(k, j) && dp[i-1][k] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + cost);
                    }
                }
            }
        }
        
        // Find minimum changes
        int ans = INT_MAX;
        for (int j = 1; j <= 6; j++) {
            ans = min(ans, dp[n][j]);
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
