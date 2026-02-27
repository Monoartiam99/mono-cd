#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        set<int> winners;
        
        for(int start = 0; start < n; start++){
            int b[n];
            for(int i = 0; i < n; i++) b[i] = a[i];
            
            int curr = start;
            int last = -1;
            
            while(true){
                bool done = true;
                for(int i = 0; i < n; i++){
                    if(b[i] > 0){
                        done = false;
                        break;
                    }
                }
                if(done) break;
                
                while(b[curr] == 0) curr = (curr + 1) % n;
                
                b[curr]--;
                last = curr;
                curr = (curr + 1) % n;
            }
            
            winners.insert(last);
        }
        
        cout << winners.size() << endl;
    }
    return 0;
}

