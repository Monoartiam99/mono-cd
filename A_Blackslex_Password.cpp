#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int t;
    cin >> t;
    
    while(t--) {
        int k, x;
        cin >> k >> x;
        
        // The answer is k * x + 1
        // We can have at most k positions in each residue class modulo x
        // There are x residue classes, so maximum length is k * x
        // Therefore, minimum invalid length is k * x + 1
        cout << k * x + 1 << "\n";
    }
     
    return 0;
}
