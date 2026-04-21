#include <bits/stdc++.h>
using namespace std;

int solve(int n, string row1, string row2) {
    const int INF = 1e9;
    
    // dp[i][j] where j represents:
    // -1: no cells waiting
    //  0: top cell waiting
    //  1: bottom cell waiting
    map<int, int> dp, new_dp;
    dp[-1] = 0;
    
    for (int i = 0; i < n; i++) {
        new_dp.clear();
        
        for (auto& [waiting, cost] : dp) {
            if (cost == INF) continue;
            
            char top = row1[i];
            char bot = row2[i];
            
            if (waiting == -1) {
                // No cells waiting
                
                // Option 1: Pair column i vertically
                int vertical_cost = (top != bot) ? 1 : 0;
                if (new_dp.find(-1) == new_dp.end()) {
                    new_dp[-1] = cost + vertical_cost;
                } else {
                    new_dp[-1] = min(new_dp[-1], cost + vertical_cost);
                }
                
                // Option 2: Leave top cell waiting
                if (new_dp.find(0) == new_dp.end()) {
                    new_dp[0] = cost;
                } else {
                    new_dp[0] = min(new_dp[0], cost);
                }
                
                // Option 3: Leave bottom cell waiting
                if (new_dp.find(1) == new_dp.end()) {
                    new_dp[1] = cost;
                } else {
                    new_dp[1] = min(new_dp[1], cost);
                }
                
            } else if (waiting == 0) {
                // Top cell waiting from column i-1
                // Must pair row1[i-1] with row1[i]
                int pair_cost = (row1[i-1] != top) ? 1 : 0;
                
                // After pairing top, bottom of column i is now waiting
                if (new_dp.find(1) == new_dp.end()) {
                    new_dp[1] = cost + pair_cost;
                } else {
                    new_dp[1] = min(new_dp[1], cost + pair_cost);
                }
                
            } else if (waiting == 1) {
                // Bottom cell waiting from column i-1
                // Must pair row2[i-1] with row2[i]
                int pair_cost = (row2[i-1] != bot) ? 1 : 0;
                
                // After pairing bottom, top of column i is now waiting
                if (new_dp.find(0) == new_dp.end()) {
                    new_dp[0] = cost + pair_cost;
                } else {
                    new_dp[0] = min(new_dp[0], cost + pair_cost);
                }
            }
        }
        
        dp = new_dp;
    }
    
    return dp[-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string row1, row2;
        cin >> n >> row1 >> row2;
        
        cout << solve(n, row1, row2) << "\n";
    }
    
    return 0;
}
