#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        // Check if string contains "2026"
        if (s.find("2026") != string::npos) {
            cout << 0 << endl;
        }
        // Check if string contains "2025"
        else if (s.find("2025") != string::npos) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    
    return 0;
}
