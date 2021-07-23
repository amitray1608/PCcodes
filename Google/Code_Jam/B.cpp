
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  string s;
  cin >> s;
  string ss;
  for (char c : s) {
    if (ss.back() != c)
      ss.push_back(c);
  }
  s = ss;
  int n = (int)s.length();
  vector<int> dp(n, -1);
  
  auto costs = [&](int i, string t) {
    if (i == n - 1) {
      return 0;
    }
    if (t.substr(i, 2) == "CJ")
      return x;
    else if (t.substr(i, 2) == "JC")
      return y;
    else
      return 0;
  };
  
  function <int(int, string)> recc = [&](int i, string t) {
    if (i < 0) return 0;
    int &ans = dp[i];
    cout << t << '\n';
    if (ans != -1) return ans;
    ans = INT_MAX;
    if (t[i] == '?') {
      t[i] = 'C';
      ans = min(ans, recc(i - 1, t) + costs(i, t)); 
      t[i] = 'J';
      ans = min(ans, recc(i - 1, t) + costs(i, t)); 
    } else {
      ans = min(ans, recc(i - 1, t) + costs(i, t));
    }
    return ans;
  };
  recc(n - 1, s);
  for (int i : dp) {
    cout << i <<  ' ';
  }
  cout << '\n';
  cout << dp[n - 1] << '\n';
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


