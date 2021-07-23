
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  string s;
  cin >> s;
  string ss;
  for (char c : s) {
    if (c != ss.back())
      ss.push_back(c);
  }
  s = ss;
  if (s.front() == '?'){
    reverse(s.begin(), s.end());
    s.pop_back();
    reverse(s.begin(), s.end());
  }
  if (s.back() == '?')
    s.pop_back();
  int n = (int)s.length();
  auto costs = [&](int i, string t) {
    if (t.substr(i - 1, 2) == "CJ")
      return x;
    else if (t.substr(i - 1, 2) == "JC")
      return y;
    else
      return 0;
  };
  
  int cost = 0;
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == '?') {
       s[i] = 'J';
       int xx = costs(i, s);
       s[i] = 'C';
       int  yy = costs(i, s);
       if (xx < yy) s[i] = 'J';
    } 
  }
  for (int i = 1; i < n; i++)
    cost += costs(i, s);
  cout << cost << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


