#include<bits/stdc++.h>
using namespace std;

const int mxn = 3e5 + 7;
int parent[mxn];
int sz[mxn];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int findrep(int u) {
    if (parent[u] = u) return u;
    parent[u] = findrep(parent[u]);
    return parent[u];
}
void unite(int u, int v) {
    u = findrep(u);
    v = findrep(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    parent[u] = v;
    sz[v] += sz[u];
}
bool check(int u, int v) {
    return findrep(u) == findrep(v);
}
int get_size(int u) {
    return sz[findrep(u)];
}

int main() {

    int n; cin >> n;
    init(n);

}
