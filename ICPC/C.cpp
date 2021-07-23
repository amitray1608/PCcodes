
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> dis;
  vector<array<int, 3>> edges;
  dis.resize(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dis[i][j];
      if (i != j and i < j)
        edges.push_back({dis[i][j], i, j});
    }
  }
  sort(edges.begin(), edges.end());
  vector<array<int, 3>> res;
  res.push_back(edges[0]);
  for (int i = 1; i < n; i++) {
    auto x = edges[i];
    int u =  
  }
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


