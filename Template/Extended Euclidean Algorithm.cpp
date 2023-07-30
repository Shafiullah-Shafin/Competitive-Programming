#include<bits/stdc++.h>
using namespace std;

pair<int, int> extendedEuclid(int a, int b) {
    if (b == 0) return {1, 0};
    auto ret = extendedEuclid(b, a % b);
    int xr = ret.first;
    int yr = ret.second;
    int x = yr;
    int y = xr - (a / b) * yr;
    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << "gcd(a, b) = ax + by" << '\n';
    int a, b; cin >> a >> b;
    auto xy = extendedEuclid(a, b);
    int x = xy.first, y = xy.second;
    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
    return 0;
}
