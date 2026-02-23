#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, s, x;
        cin >> n >> s >> x;
        
        vector<int> a(n);
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        
        int diff = s - sum;
        
        // If difference is negative, we can't achieve target sum
        // (we can only add, not subtract)
        if (diff < 0) {
            cout << "NO" << endl;
        }
        // If difference is divisible by x, we can achieve target sum
        else if (diff % x == 0) {
            cout << "YES" << endl;
        }
        // Otherwise, it's impossible
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}