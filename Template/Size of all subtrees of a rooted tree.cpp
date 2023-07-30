#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int sz[N];
vector<int> g[N];
void dfs(int u, int p) {
  sz[u] = 1;
  for (auto v: g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << sz[i] << ' ';
  }
  return 0;
}
