
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int &i : a) {
    cin >> i;
    mp[i]++;
  }
  for (auto &i : mp) {
    cout << i.first << ' ';
    i.second--;
  }
  for (auto i : mp) {
    int x = i.second;
    while (x--) {
      cout << i.first << ' ';
    }
  }
  cout << '\n';

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


