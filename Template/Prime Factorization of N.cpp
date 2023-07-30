// Number of divisor
// Sum of Divisor
// lcm of 2 numbers
// gcd of 2 numbers
// Smallest Prime Factor finding
// Complexity: O(sqrt(n))
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int power = 0;
            while (n % i == 0) {
                power++;
                n /= i;
            }
            v.push_back({i, power});
        }
    }
    if (n > 1) v.push_back({n, 1});
    for (auto x: v) {
         cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}
