#include<bits/stdc++.h>
using namespace std;

const int mxn = 3e5 + 7;
vector<int> g[mxn];
int par[mxn][20], dep[mxn], sz[mxn];

void dfs(int u, int p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= 18; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto v: g[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int k = dep[u] - dep[v];
    for (int i = 18; i >= 0; i--) {
        if (k == 0) break;
        if (k & (1 << i)) {
            u = par[u][i];
            k ^= (1 << i);
        }
    }
    if (u == v) return u;
    for (int i = 18; i >= 0; i--) {
        if (par[u][k] != par[v][k]) {
            u = par[u][k];
            v = par[v][k];
        }
    }
    return par[u][0];
}
int kth(int u, int k) {
    assert(k >= 0);
    for (int i = 0; i <= 18; i++) {
        if (k & (1 << i)) u = par[u][i];
    }
    return u;
}
int dist(int u, int v) {
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
}
//kth node from u to v, 0th node is u
int go(int u, int v, int k) {
    int l = lca(u, v);
    int d = dep[u] + dep[v] - (dep[l] << 1);
    assert(k <= d);
    if (dep[l] + k <= dep[u]) return kth(u, k);
    k -= dep[u] - dep[l];
    return kth(v, dep[v] - dep[l] - k);
}

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << dist(u, v) << '\n';
    }
    return 0;
}
