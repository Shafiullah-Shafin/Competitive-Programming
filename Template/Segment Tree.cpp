#include<bits/stdc++.h>
using namespace std;

const int mx = 3e5 + 7;
const int inf = 1e9 + 7;
int t[mx * 4];
int a[mx + 2];

void build(int node, int b, int e) {
     if (b == e) {
        t[node] = a[b];
        return;
     }
     int mid = (b + e) >> 1, l = node << 1, r = l | 1;
     build(l, b, mid);
     build(r, mid + 1, e);
     t[node] = max(t[l], t[r]);
}
void update(int node, int b, int e, int i, int x) {
     if (b > i || e < i) return;
     if (b == e && b == i) {
        t[node] = x;
        return;
     }
     int mid = (b + e) >> 1, l = node << 1, r = l | 1;
     update(l, b, mid, i, x);
     update(r, mid + 1, e, i, x);
     t[node] = max(t[l], t[r]);
}
int query(int node, int b, int e, int i, int j) {
    if (b > j || e < i) return -inf;
    if (b >= i && e <= j) return t[node];
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    int x = query(l, b, mid, i, j);
    int y = query(r, mid + 1, e, i, j);
    return max(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {

    }
    return 0;
}
