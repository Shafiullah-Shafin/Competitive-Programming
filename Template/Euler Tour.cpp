#include<bits/stdc++.h>
using namespace std;

const int mxn = 3e5 + 7;
vector<int> g[mxn + 2];
int in[mxn], out[mxn], timer;

void dfs(int u, int p = 0) {
    in[u] = ++timer;
    for (auto v: g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    out[u] = ++timer;
}
// Whether u is an ancestor of v
bool ancestor(int u, int v) {
     return ((in[u] < in[v]) && (out[u] > out[v]));
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
        if (ancestor(u, v)) cout << "u is an ancestor of v" << '\n';
        else cout << "u isn't an ancestor of v" << '\n';
    }
    return 0;
}
