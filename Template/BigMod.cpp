// This is used when : a^n % mod and a, n, mod <= 10^18 and mod is a prime
// Complexity : O(log(n))
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int BigMod1 (int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
       int x = BigMod (a, n / 2);
       return 1LL * x * x % mod;
    }
    else {
       int x = BigMod (a, n / 2);
       return (1LL * x * x) % mod * a % mod;
    }
}

long long BigMod2 (long long b, long long p) {
    long long ans = 1;
    while (p) {
        if (p & 1) ans = ((ans % mod) * (b % mod)) % mod;
        p = (p >> 1);
        b = ((b % mod) * (b % mod)) % mod;
    }
    return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, n;
  cin >> a >> n;
  cout << BigMod1 (a, n) << '\n';
  cout << BigMod2 (a, n) << '\n';
  return 0;
}
