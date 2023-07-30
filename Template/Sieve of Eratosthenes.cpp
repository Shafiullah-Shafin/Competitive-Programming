// Number of Primes from 1 to N
// Complexity: O(nlog(log(n)))
#include<bits/stdc++.h>
using namespace std;

const int n = 1e7;
bool f[n + 2];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> primes;
    f[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!f[i]) {
           primes.push_back(i);
           for (int j = i + i; j <= n; j += i) {
               f[j] = true;
           }
        }
    }
    cout << (int)primes.size() << '\n';
    return 0;
}
