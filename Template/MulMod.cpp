// MulMod is used to control overflow, when : a^b % m, a, b, m all are big number (a, b, m <= 10^18)
// To avoid overflow, we can also use builtin data type __int128 (in C++17) which is 128 bit integer
// We can't do cin operation over a variable of __int128 datatype, we can do cout operation only.

include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

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
  cout << __int128(a) * n % mod << '\n';
  return 0;
}
