#include <iostream>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    
    // Calculate number of flagstones needed in each dimension
    // ceil(n/a) = (n + a - 1) / a for integer division
    long long flagstones_n = (n + a - 1) / a;
    long long flagstones_m = (m + a - 1) / a;
    
    // Total flagstones needed
    long long total = flagstones_n * flagstones_m;
    
    cout << total << endl;
    
    return 0;
}