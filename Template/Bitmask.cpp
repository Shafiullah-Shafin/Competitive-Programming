#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    int a[n + 2];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    set<int> se;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;
        se.clear();
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1)
               sum += a[i];
        }
        if (se.size() == cnt && cnt <= k)
           ans++;
    }
    cout << cnt << '\n';
    return 0;
}
