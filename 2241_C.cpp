#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        char buf[105];
        scanf("%s", buf);
        
        int blocks = 1;
        for (int i = 1; i < n; i++) {
            if (buf[i] != buf[i-1]) blocks++;
        }
        
        if (blocks == 2) printf("2\n");
        else printf("1\n");
    }
    return 0;
}