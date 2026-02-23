// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     // ios::sync_with_stdio(false);
//     // cin.tie(nullptr);

//     int q;
//     if(!(cin >> q)) return 0;
//     while(q--){
//         int n;
//         cin >> n;
//         string s, t;
//         // read both strings once
//         cin >> s >> t;

//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());

//         if (s == t) cout << "YES\n";
//         else cout << "NO\n";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
