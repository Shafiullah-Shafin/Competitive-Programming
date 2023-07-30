#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v({1, 2, 4, 4, 4, 6, 6, 9});
  int x = 4;
  if (binary_search(v.begin(), v.end(), x)) {
    cout << "YES\n";
  }
  auto it = lower_bound(v.begin(), v.end(), x); // first one >= x
  cout << (it - v.begin()) << '\n';
  it = upper_bound(v.begin(), v.end(), x); // first one > x
  cout << (it - v.begin()) << '\n';

  int count_of_x = upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x);
  cout << count_of_x << '\n';
  return 0;
}
