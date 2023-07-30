#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        pair<int, int> a[n + 2];
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
        } 
        for (int i = 1; i <= n; i++) {
            cin >> a[i].second;
        } 
        sort(a + 1, a + n + 1);
        double ans = 0, l = a[0].first, r = a[n].first;
        while (abs(l - r) > 1e-7) {
            double mid1 = l + (r - l) / 3;
            double mid2 = r - (r - l) / 3;
            double cost1 = 0, cost2 = 0;
            for (int i = 1; i <= n; i++) {
                double now = a[i].second + abs((double)a[i].first - mid1);
                cost1 = max(cost1, now);
            }
            for (int i = 1; i <= n; i++) {
                double now = a[i].second + abs((double)a[i].first - mid2);
                cost2 = max(cost2, now);
            }
            if (cost1 - cost2 < 1e-7) {
                ans = mid1;
                r = mid2;
            }
            else {
                ans = mid2;
                l = mid1;
            }
        }
        cout << setprecision(7) << fixed << ans << '\n';
    }
    return 0;
}