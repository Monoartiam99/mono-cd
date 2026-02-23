#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calculate_value(const vector<int>& a) {
    long long total = 0;
    int current_max = 0;
    for (int x : a) {
        current_max = max(current_max, x);
        total += current_max;
    }
    return total;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_val = calculate_value(a);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(a[i], a[j]);
            max_val = max(max_val, calculate_value(a));
            swap(a[i], a[j]); // swap back
        }
    }

    cout << max_val << endl;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
