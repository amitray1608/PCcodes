#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  
  vector<char> ch(26);
  iota(ch.begin(), ch.end(), 'a');
  map<char, set<string>> mp;
  long long count = 0;
  for (int i = 0; i < n; i++) {
    string x = s[i].substr(1);
    mp[s[i][0]].insert(x);
  }

  for (char c : ch) {
    for (char d : ch) {
      int a = 0, b = 0;
      if (c == d) continue;
      for (string it : mp[c]) {
        if (mp[d].size()) {
          if (mp[d].find(it) == mp[d].end())
            a++;
        }
      }
      for (string it : mp[d]) {
        if (mp[c].size()) {
          if (mp[c].find(it) == mp[c].end())
            b++;
        }
      }
      count += a * b;
    }
  }
  cout << count << '\n';
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


