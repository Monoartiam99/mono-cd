#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int max_gap = a[0]; // distance from 0 to first station
        
        for (int i = 1; i < n; i++) {
            max_gap = max(max_gap, a[i] - a[i - 1]);
        }
        
        // distance from last station to x
        int last_gap = (x - a[n - 1]) * 2;
        max_gap = max(max_gap, last_gap);
        
        cout << max_gap << "\n";
    }
    return 0;
}
