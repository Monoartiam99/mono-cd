#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Count chains of consecutive integers
        // Each chain segment starts a new original element
        int chains = 1;
        
        for (int i = 0; i < n - 1; i++) {
            // When consecutive integers break, we start a new chain
            if (a[i] + 1 != a[i + 1]) {
                chains++;
            }
        }
        
        cout << chains << "\n";
    }
    
    return 0;
}
