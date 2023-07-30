// MulMod is used to control overflow, when : a^b % m, a, b, m all are big number (a, b, m <= 10^18)
// To avoid overflow, we can also use builtin data type __int128 (in C++17) which is 128 bit integer
// We can't do cin operation over a variable of __int128 datatype, we can do cout operation only.

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll BigMod(ll n, ll k) {
  int ans = 1 % mod; n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = 1LL * ans * n % mod;
    n = 1LL * n * n % mod;
    k >>= 1;
  }
  return ans;
}

long long MulMod (long long a, long long n) {
    if (n == 1) return a % mod;
    if (n % 2 == 0) {
       long long x = MulMod (a, n / 2);
       return (x + x) % mod;
    }
    else {
       long long x = MulMod (a, n / 2);
       return (x + x) % mod + a % mod;
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, n;
  cin >> a >> n;
  cout << MulMod (a, n) << '\n';
  int x = (__int128(a) * n) % mod;
  cout << x << '\n';
  cout << BigMod (a, n) << '\n';
  return 0;
}
