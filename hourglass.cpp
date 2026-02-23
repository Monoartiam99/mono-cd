#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long s, k, m;
        cin >> s >> k >> m;
        
        // Simulate the flips to find the sand amount at the last flip
        long long current_sand = s;  // Initially s minutes of sand
        long long time = 0;
        
        // Flip every k minutes while time + k <= m
        while (time + k <= m) {
            time += k;
            // Amount of sand that fell to bottom = min(current_sand, k)
            long long sand_fallen = min(current_sand, k);
            // After flip, this amount starts falling again
            current_sand = sand_fallen;
        }
        
        // Calculate time passed since last flip
        long long time_passed = m - time;
        // Remaining sand = current_sand - time_passed (but at least 0)
        long long remaining = max(0LL, current_sand - time_passed);
        
        cout << remaining << endl;
    }
    
    return 0;
}
