#include <bits/stdc++.h>

using namespace std;

int n, m, k, maxi = 0;
vector<pair<int, int>> a, b;

void recc(vector<int> x, int pos) {
  if (pos == k) {
    int count = 0;
    for (auto i : a) {
      if (x[i.first] and x[i.second]) count++;
    }
    maxi = max(count, maxi);
    return;
  }
  
  x[b[pos].first]++;
  recc(x, pos + 1);
  x[b[pos].first]--;
  
  x[b[pos].second]++;
  recc(x, pos + 1);
  x[b[pos].second]--;
}

void solve() {
  cin >> n >> m;
  a.resize(m);
  for (auto &i : a) cin >> i.first >> i.second;
  cin >> k;
  b.resize(k);
  for (auto &i : b) cin >> i.first >> i.second;  
  vector<int> x(n + 1, 0);
  recc(x, 0); 
  cout << maxi << '\n';  
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


