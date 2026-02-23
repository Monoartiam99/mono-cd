#include <bits/stdc++.h>
using namespace std;

int digitSum(long long n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
   

    int t;
    cin >> t;
    while(t--) {
        long long x;
        cin >> x;

        int ans = 0;

        for(long long y = x; y <= x + 90; y++) {
            if(y - digitSum(y) == x)
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}
