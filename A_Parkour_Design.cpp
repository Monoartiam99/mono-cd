#include <bits/stdc++.h>
using namespace std;

int main() {
   
    
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Check if (x - 2y) is divisible by 3
        if ((x - 2 * y) % 3 != 0) {
            cout << "NO\n";
            continue;
        }
        
        // If y >= 0: need x >= 2y
        // If y < 0: need x >= 4|y| = -4y
        if (y >= 0) {
            if (x >= 2 * y) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if (x >= -4 * y) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}
