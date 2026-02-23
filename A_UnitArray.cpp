// #include <bits/stdc++.h>
// using namespace std;

// int main() {
    

//     int t;
//     if (!(cin >> t)) 
//     return 0;
//     while (t--) {
//         int n; 
//         cin >> n;
//         int cnt_neg = 0;
//         for (int i = 0; i < n; ++i) {
//             int x; 
//             cin >> x;
//             if (x == -1) 
//             ++cnt_neg;
//         }
//         int limit = n / 2; // maximum allowed -1s to have sum >= 0
//         int need = max(0, cnt_neg - limit);
//         int remaining = cnt_neg - need; // parity after doing 'need' flips
//         if (remaining % 2 == 0) {
//         cout << need << '\n';
//         }
//         else {
//         cout << need + 1 << '\n';
//     }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Length of the array
        cin >> n;
        long long a[n]; // Array to store elements
        for (long long i = 0; i < n; i++) // Loop to read array elements
            cin >> a[i];
        // Input complete

        long long positive_count = 0; // Count of +1s in the array
        long long negative_count = 0; // Count of -1s in the array
        for (long long i = 0; i < n; i++) // Loop to count +1s and -1s
        {
            if (a[i] == 1)
                positive_count++;
            else
                negative_count++;
        }

        long long operations = 0; // Number of operations needed to make the array good
        // While the sum of the array is negative or the product condition is not met
        while (positive_count < negative_count || negative_count % 2 == 1) // Loop to make array good
        {
            operations++; // Increment operations as we convert a -1 to 1
            positive_count++; // Increase count of +1s
            negative_count--; // Decrease count of -1s
        }

        cout << operations << endl; // Output the result for the current test case
    }
    return 0;
}
