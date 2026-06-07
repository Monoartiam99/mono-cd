#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;

        ll diff = (x1 > x2) ? (x1 - x2) : (x2 - x1);
        ll d = min(diff, n - diff);
        ll ans = min(d + k, n / 2);

        cout << ans << "\n";
    }
    return 0;
}