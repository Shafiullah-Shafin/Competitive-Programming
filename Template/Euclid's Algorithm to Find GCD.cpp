// Built-in Function : __gcd(a, b)
// Complexity: O(log(min(a, b)))
#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a < b) swap(a, b);
    return GCD(a % b, b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << GCD(10, 15) << '\n';
    return 0;
}
