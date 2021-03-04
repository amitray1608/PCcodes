#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (mp.find(s) == mp.end()) count++;
    else mp[s]--;
    if (mp[s] == 0) {
      mp.erase(s);
    }
  }
  cout << count << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


