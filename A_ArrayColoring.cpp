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
        
        // Create a sorted version to find positions
        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());
        
        // Map each value to its position in sorted array
        map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[sorted_a[i]] = i;
        }
        
        // Check if adjacent elements in original array have different parity positions
        bool valid = true;
        for (int i = 0; i < n - 1; i++) {
            int pos1 = pos[a[i]];
            int pos2 = pos[a[i + 1]];
            
            // Adjacent elements must have different parity positions
            if (pos1 % 2 == pos2 % 2) {
                valid = false;
                break;
            }
        }
        
        cout << (valid ? "YES" : "NO") << endl;
    }
    
    return 0;
}
