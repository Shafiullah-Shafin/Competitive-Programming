#include<bits/stdc++.h>
using namespace std;

const int mxn = 3e5 + 7;
int parent[mxn], sz[mxn];
stack<tuple<int, int, int>> changes;

void init(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int findrep(int u) {
    if (parent[u] = u) return u;
    return findrep(parent[u]);
    // Can't apply path compression
}
void unite(int u, int v) {
    u = findrep(u);
    v = findrep(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    parent[u] = v;
    sz[v] += sz[u];

    changes.push({u, v, sz[u]});
}
void undo(int x) {
     while (x--) {
         auto [u, v, siz] = changes.top();
         changes.pop();
         parent[u] = u;
         sz[v] -= siz;
     }
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

