#include <bits/stdc++.h>
using namespace std;

int oddPart(int x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    return x;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        map<int, vector<int>> positionsByOddPart;
        map<int, vector<int>> valuesByOddPart;
        
        for (int i = 1; i <= n; i++) {
            int op = oddPart(i);
            positionsByOddPart[op].push_back(i);
            valuesByOddPart[op].push_back(a[i]);
        }
        
        bool possible = true;
        for (auto& p : positionsByOddPart) {
            int op = p.first;
            vector<int> positions = p.second;
            vector<int> values = valuesByOddPart[op];
            sort(positions.begin(), positions.end());
            sort(values.begin(), values.end());
            if (positions != values) {
                possible = false;
                break;
            }
        }
        
        cout << (possible ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
