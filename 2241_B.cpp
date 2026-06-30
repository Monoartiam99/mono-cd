#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        string x;
        cin >> x;
        int L = x.size();
        long long y = 1;
        for (int i = 0; i < L; i++) y *= 10;
        y += 1;
        cout << y << "\n";
    }
    return 0;
}