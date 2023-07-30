#include<bits/stdc++.h>
using namespace std;

const int N = 1e6, mod = 1e9 + 7;

int power(long long n, long long k) {
    int ans = 1 % mod; n %= mod;
    if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}
int fact[N + 2], invf[N + 2];
int nCr(int n, int r) {
    if (n < r || n < 0) return 0;
    return 1LL * fact[n] * invf[r] % mod * invf[n - r] % mod;
}
int nPr(int n, int r) {
    if (n < r || n < 0) return 0;
    return 1LL * fact[n] * invf[n - r] % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * i * fact[i - 1] % mod;
    }
    invf[N - 1] = power(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
    cout << nCr(6, 2) << '\n';
    cout << nPr(6, 2) << '\n';
    return 0;
}
