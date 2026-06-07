#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        // Step 1: Every '4' must be deleted (it's a subsequence divisible by 4 by itself)
        int fours = count(s.begin(), s.end(), '4');

        // Step 2: From remaining {1,2,3} digits, eliminate all '12' and '32' subsequences.
        // A '2' is dangerous iff a '1' or '3' appears before it.
        // We need: all '1'/'3' come AFTER all '2's (no 1/3 before any 2).
        // Min deletions = min over split point i of:
        //   (count of '1'/'3' in prefix) + (count of '2' in suffix)
        string r = "";
        for(char c : s) if(c != '4') r += c;

        int n = r.size();
        vector<int> pre13(n+1, 0), suf2(n+1, 0);
        for(int i = 0; i < n; i++)
            pre13[i+1] = pre13[i] + (r[i]=='1' || r[i]=='3' ? 1 : 0);
        for(int i = n-1; i >= 0; i--)
            suf2[i] = suf2[i+1] + (r[i]=='2' ? 1 : 0);

        int best = n;
        for(int i = 0; i <= n; i++)
            best = min(best, pre13[i] + suf2[i]);

        cout << fours + best << "\n";
    }

    return 0;
}