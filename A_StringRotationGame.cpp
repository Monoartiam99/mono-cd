#include <bits/stdc++.h>
using namespace std;

int countBlocks(const string& s) {
    if (s.empty()) return 0;
    int blocks = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i-1]) {
            blocks++;
        }
    }
    return blocks;
}

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int maxScore = 0;
        
        for (int i = 0; i < n; i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            int score = countBlocks(rotated);
            maxScore = max(maxScore, score);
        }
        
        
        cout << maxScore << "\n";
    }
    
    return 0;
}
