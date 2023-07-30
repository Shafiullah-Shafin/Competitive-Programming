#include<bits/stdc++.h>
using namespace std;

#define i64 long long
const i64 inf = 1e18;
const int mxn = 3e5 + 7;
int u[mxn], v[mxn], w[mxn];
vector<pair<int, int>> g[mxn], r[mxn];

vector<i64> dijkstra(int src, int n) {
  priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
  vector<i64> dis(n + 1, inf);
  vector<bool> vis(n + 1, false);
  pq.push({0, src});
  dis[src] = 0;
  while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (auto [v, w] : g[u]) {
          if (dis[u] + w < dis[v]) {
             dis[v] = dis[u] + w;
             pq.push({dis[v], v});
          }
      }
  }
  return dis;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back({v[i], w[i]});
        r[v[i]].push_back({u[i], w[i]});
    }
    int src = 0;
    dijkstra(src, n);
    return 0;
}
