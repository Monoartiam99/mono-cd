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
        
        sort(a.begin(), a.end());
        
        // Option 1: target = 0, k = minimum element
        int k1 = a[0];
        
        // Option 2: target = minimum element, k = second_min - min
        int k2 = a[1] - a[0];
        
        cout << max(k1, k2) << "\n";
    }
    
    return 0;
}
