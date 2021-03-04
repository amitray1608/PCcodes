
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = "trygub";
  string ans = "";
  map<char, int> mp;
  for (char c : s) {
    bool ok = false;
    for (char cc : t) {
      if (c == cc) {
        mp[c]++;
        ok = true;
        break;
      }
    }
    if (!ok)
      ans += c;
  }
  sort(t.begin(), t.end());
  for (char c : t) {
    string x = "";
    if (mp.find(c) != mp.end())
      x = string(mp[c], c);
    ans += x;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


