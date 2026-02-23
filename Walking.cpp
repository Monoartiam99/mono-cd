#include <bits/stdc++.h>
using namespace std;

// operation types:
// 1. Move Up and Right
// 2. Move Left

int main()
{
    int t;
    cin >> t; 
    while (t--)
    {
        //Source =a, Destination = b
        int a_x, a_y, b_x, b_y;
        cin >> a_x >> a_y >> b_x >> b_y;
        if (b_y < b_y) 
        {
            cout << -1 << endl; 
            continue;
        int moves = b_y - a_y; 
        a_x += moves; 
        if (a_x < b_x) 
        {
            cout << -1 << endl; 
            continue; 
        }

        moves += (a_x - b_x); 
        cout << moves << endl; 
    return 0;
}

}
}


