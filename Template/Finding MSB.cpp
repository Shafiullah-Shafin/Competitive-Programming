#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n = 135042752573501;
    cout << bitset<63> (n) << '\n';
    int msb1 = (int)log2(n);             // 0-based position
    int msb2 = 63 - __builtin_clzll(n);  // o-based position
    int msb3 = 0; 
    for (int i = 1; i <= 64; i++) {      // 1-based position, to make it 0 based do : for (int i = 1; i <= 63; i++)
        if (n & 1) msb3 = i;
        n /= 2;
        if (n == 0) break;
    }
    cout << msb1 << '\n' << msb2 << '\n' << msb3 << '\n';
    return 0;
}
