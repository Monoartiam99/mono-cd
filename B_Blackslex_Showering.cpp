#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Calculate original sum
        int total = 0;
        for(int i = 0; i < n-1; i++) {
            total += abs(a[i] - a[i+1]);
        }
        
        // Find maximum savings by skipping one floor
        int max_savings = 0;
        
        // Try skipping each floor
        for(int k = 0; k < n; k++) {
            int savings = 0;
            
            if(k == 0) {
                // Skip first floor
                savings = abs(a[0] - a[1]);
            } else if(k == n-1) {
                // Skip last floor
                savings = abs(a[n-2] - a[n-1]);
            } else {
                // Skip middle floor: remove 2 edges, add 1 edge
                savings = abs(a[k-1] - a[k]) + abs(a[k] - a[k+1]) - abs(a[k-1] - a[k+1]);
            }
            
            max_savings = max(max_savings, savings);
        }
        
        cout << total - max_savings << "\n";
    }
    
    return 0;
}
