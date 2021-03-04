#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  map<string, string> mp;
  map<string, bool> given;
  mp["purple"] = "Power";
  mp["green"] = "Time";
  mp["blue"] = "Space";
  mp["orange"] = "Soul";
  mp["red"] = "Reality";
  mp["yellow"] = "Mind";
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    given[s] = true;
  }
  vector<string> res;
  int count = 0;
  for (auto i : mp) {
    if (given.find(i.first) == given.end()) {
      count++;
      res.push_back(i.second);
    }
  }
  cout << count << '\n';
  for (auto i : res) cout << i << '\n';
  cout << '\n';
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


