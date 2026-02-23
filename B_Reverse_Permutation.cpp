#include <bits/stdc++.h>
using namespace std;

int main() {
 
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        
        vector<int> best = p;
        
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                vector<int> current = p;
                
                reverse(current.begin() + l, current.begin() + r + 1);
                
                if (current > best) {
                    best = current;
                }
            }
        }
    
        for (int i = 0; i < n; i++) {
            cout << best[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}