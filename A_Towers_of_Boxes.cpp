#include <bits/stdc++.h>

int main() {
    

    int t = 0;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n = 0;
        int m = 0;
        int d = 0;
        std::cin >> n >> m >> d;

        int max_height = d / m + 1; // Bottom box must support (height-1) boxes.
        int towers = (n + max_height - 1) / max_height;
        std::cout << towers << '\n';
    }

    return 0;
}
