#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string X;
    cin >> X;
    
    int start = 0;
    if (n % 2 == 1) {
        if (X[0] == 'b') {
            cout << "NO\n";
            return;
        }
        start = 1;
    }
    
    for (int i = start; i < n; i += 2) {
        char c1 = X[i];
        char c2 = (i + 1 < n) ? X[i + 1] : '?';
        if (c1 != '?' && c2 != '?' && c1 == c2) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}

int main() {
   
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}