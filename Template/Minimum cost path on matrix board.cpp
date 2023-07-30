#include<bits/stdc++.h>
using namespace std;

int n, m, a[10][10], inf = 1e9 + 7;
int dp[10][10];
int min_cost(int i, int j) {
  if (j > m or i > n) return inf;
  if (i == n and j == m) return a[i][j];
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = a[i][j] + min(min_cost(i + 1, j), min_cost(i, j + 1));
}
void path(int i, int j) {
  cout << "(" << i << ", " << j << ") -> ";
  if (i == n and j == m) return;
  int right = min_cost(i, j + 1);
  int down = min_cost(i + 1, j);
  if (right <= down) {
    path(i, j + 1);
  }
  else {
    path(i + 1, j);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof dp);
  cout << min_cost(1, 1) << '\n';
  path(1, 1);
  return 0;
}
