#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(long long i=0;i<n;i++)
            cin >> a[i];
        //input complete

        long long operations_count =0;
        for(long long i=0;i<n-1;i++)
        {
            if((a[i]%2) == (a[i+1]%2))
                operations_count++;
        }
        cout << operations_count << endl;   
    }
    return 0;
}