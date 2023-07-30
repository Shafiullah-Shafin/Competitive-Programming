#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  getline(cin, s);
  stringstream ss;
  ss << s;
  string word;
  while (ss >> word) {
    cout << word << '\n';
  }
  return 0;
}
