#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (n == k) {
            cout << 0 << endl;
            continue;
        }

        if (k > n) {
            cout << -1 << endl;
            continue;
        }

        queue<pair<long long, int>> q; 
        map<long long, int> visited;   
        
        q.push({n, 0});
        visited[n] = 0;
        
        int result = -1;
        
        while (!q.empty()) {
            long long x = q.front().first;
            int time = q.front().second;
            q.pop();

            if (x < k) continue;

            long long left = x / 2;           // floor(x/2)
            long long right = (x + 1) / 2;    // ceil(x/2)

            if (left == k || right == k) {
                result = time + 1;
                break;
            }

            if (visited.find(left) == visited.end()) {
                visited[left] = time + 1;
                q.push({left, time + 1});
            }
            
            if (left != right && visited.find(right) == visited.end()) {
                visited[right] = time + 1;
                q.push({right, time + 1});
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}
