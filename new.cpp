#include <bits/stdc++.h>
using namespace std;

bool canAchieve(long long maxVal, int m, vector<long long>& intervals) {
    // Check if we can keep all animatronics at danger <= maxVal
    // by flashing optimally in each interval
    vector<long long> dmg(m, 0);
    
    // Process each interval before a flash
    for (int i = 0; i < (int)intervals.size() - 1; i++) {
        long long interval = intervals[i];
        
        // Add damage to all animatronics
        for (int j = 0; j < m; j++) {
            dmg[j] += interval;
        }
        
        // Flash the animatronic with max damage
        long long maxDmg = *max_element(dmg.begin(), dmg.end());
        if (maxDmg > maxVal) {
            return false; // Can't keep under the limit
        }
        
        // Flash the worst one
        for (int j = 0; j < m; j++) {
            if (dmg[j] == maxDmg) {
                dmg[j] = 0;
                break;
            }
        }
    }
    
    // Final interval (no flash possible after this)
    long long finalInterval = intervals.back();
    for (int j = 0; j < m; j++) {
        dmg[j] += finalInterval;
    }
    
    long long finalMax = *max_element(dmg.begin(), dmg.end());
    return finalMax <= maxVal;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Special case: only one animatronic
        if (m == 1) {
            cout << l - a[n-1] << "\n";
            continue;
        }
        
        // Compute interval lengths
        vector<long long> intervals;
        if (n > 0) {
            intervals.push_back(a[0]);
            for (int i = 1; i < n; i++) {
                intervals.push_back(a[i] - a[i-1]);
            }
            intervals.push_back(l - a[n-1]);
        } else {
            intervals.push_back(l);
        }
        
        // Binary search for the answer
        long long left = 0, right = l;
        while (left < right) {
            long long mid = (left + right) / 2;
            if (canAchieve(mid, m, intervals)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << "\n";
    }
    
    return 0;
}


