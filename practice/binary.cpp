
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &i : s) {
      cin >> i;
    }
    sort(s.begin(), s.end());
    int sum = 0;
    
    auto get = [&](string a, string b) {
      int count = 0;
      int i = 0;
      while (i < m and a[i] == b[i]) count++, i++;
      return count; 
    };

    for (int i = 1; i < n; i++) {
      sum += (m - get(s[i], s[i - 1]));
    }
    cout << sum + m << '\n';
  }
  return 0;
} //Hajimemashite

