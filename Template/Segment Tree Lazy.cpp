#include<bits/stdc++.h>
using namespace std;

const int mx = 3e5 + 7;
const int inf = 2e9 + 7;
int a[mx + 2];
int t[mx * 4];
int lazy[mx * 4];

void build(int node, int b, int e) {
     lazy[node] = 0;
     if (b == e) {
        t[node] = a[b];
        return;
     }
     int mid = (b + e) >> 1, l = node * 2, r = l | 1;
     build(l, b, mid);
     build(r, mid + 1, e);
     t[node] = min(t[l], t[r]);
}
void propagate(int node, int b, int e) {
     if (lazy[node] == 0) return;
     t[node] += lazy[node];
     if (b != e) {
        int l = node * 2, r = l | 1;
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
     }
     lazy[node] = 0;
}
void update(int node, int b, int e, int i, int j, int x) {
     propagate(node, b, e);
     if (i > e || j < b) return;
     if (i <= b && j >= e) {
        lazy[node] += x;
        propagate(node, b, e);
        return;
     }
     int mid = (b + e) >> 1, l = node * 2, r = l | 1;
     update(l, b, mid, i, j, x);
     update(r, mid + 1, e, i, j, x);
     t[node] = min(t[l], t[r]);
}
int query(int node, int b, int e, int i, int j) {
    propagate(node, b, e);
    if (i > e || j < b) return inf;
    if (i <= b && j >= e) return t[node];
    int mid = (b + e) >> 1, l = node * 2, r = l | 1;
    int x = query(l, b, mid, i, j);
    int y = query(r, mid + 1, e, i, j);
    return min(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n, m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {

    }
    return 0;
}
