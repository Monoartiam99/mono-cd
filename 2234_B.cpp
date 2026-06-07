#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool isPalindrome(ll x) {
    if (x < 0) return false;
    string s = to_string(x);
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

int main() {
    // precompute palindromes up to 1e6
    vector<ll> pals;
    const int LIM = 1000000;
    for (int i = 0; i <= LIM; ++i) if (isPalindrome(i)) pals.push_back(i);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        ll n;
        cin >> n;

        bool found = false;
        for (ll a : pals) {
            if (a > n) break;
            if ((n - a) % 12 == 0) {
                cout << a << " " << (n - a) << "\n";
                found = true;
                break;
            }
        }

        if (!found) cout << -1 << "\n";
    }
    
    return 0;
}