#include <bits/stdc++.h>
using namespace std;

bool good(const vector<int>& a){
    int sum = 0; int prod = 1;
    for(int x: a){ sum += x; prod *= x; }
    return sum >= 0 && prod == 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; if(!(cin >> t)) return 0;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin >> a[i];
        int best = INT_MAX;
        int limit = 1<<n;
        for(int mask=0; mask<limit; ++mask){
            vector<int> b = a;
            int ops = __builtin_popcount((unsigned)mask);
            for(int i=0;i<n;++i) if(mask & (1<<i)) b[i] = -b[i];
            if(good(b)) best = min(best, ops);
        }
        if(best==INT_MAX) cout << "IMPOSSIBLE\n";
        else cout << best << '\n';
    }
    return 0;
}
