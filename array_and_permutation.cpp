#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        
        vector<int> p(n), a(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> a[i];
        
        // Find position of each value in p
        map<int, int> pos_p;
        for(int i = 0; i < n; i++){
            pos_p[p[i]] = i;
        }
        
        // Find interval [L, R] for each value in a
        map<int, pair<int, int>> interval;
        map<int, int> count_in_a;
        for(int i = 0; i < n; i++){
            count_in_a[a[i]]++;
            if(interval.find(a[i]) == interval.end()){
                interval[a[i]] = {i, i};
            } else {
                interval[a[i]].second = i;
            }
        }
        
        // Find fixed values (appear exactly once in a)
        set<int> fixed_values;
        for(auto& kv : count_in_a){
            if(kv.second == 1){
                fixed_values.insert(kv.first);
            }
        }
        
        bool valid = true;
        
        // For each distinct value in a
        for(auto& kv : interval){
            int v = kv.first;
            int L = kv.second.first;
            int R = kv.second.second;
            
            // Check if value v exists in p
            if(pos_p.find(v) == pos_p.end()){
                valid = false;
                break;
            }
            
            // Check if any fixed value (other than v) exists within [L, R]
            // Such values cannot be overwritten and would block v's spreading
            for(int i = L; i <= R; i++){
                int w = a[i];
                if(w != v && fixed_values.count(w) > 0){
                    // Fixed value w is at position i within v's interval [L, R]
                    // v cannot overwrite it - conflict!
                    valid = false;
                    break;
                }
            }
            
            if(!valid) break;
        }
        
        cout << (valid ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
